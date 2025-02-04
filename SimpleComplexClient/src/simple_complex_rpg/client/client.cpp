#include "simple_complex_rpg/client/client.h"
#include <iostream>
#include <bitset>

using namespace SimpleComplexRPG::Client;

Client::Client(boost::asio::io_context& io_context, tcp::resolver::results_type endpoints) : socket_(io_context) {
    readMsg_ = new uint8_t[SCServer::Packet::MAX_PACKET_SIZE];
    ConnectToServer(endpoints);
}

void Client::Write(const SCServer::Packet& message) {
    boost::asio::post(socket_.get_executor(),
        [this, message]() {
            bool writeInProgress = !writeMessages_.empty();
            writeMessages_.push_back(message);
            if (!writeInProgress) {
                WritePacket();
            }
        });
}

void Client::Close() {
    SCServer::Packet packet(SCServer::PacketVersion::V0, SCServer::PacketID::QUIT);
    packet.packetSender = GetID();
    packet.Serialize((uint8_t)UINT8_MAX);
    Write(packet);
    boost::asio::post(socket_.get_executor(), [this]() { socket_.close(); });
}

void Client::ConnectToServer(const tcp::resolver::results_type& endpoints) {
    boost::asio::async_connect(socket_, endpoints,
        [this](boost::system::error_code ec, tcp::endpoint) {
            if (!ec) {
                ReadPacket();
            }
        });
}


void Client::ReadPacket() {
    // Step 1: Read the packet header to get the size of the packet
    boost::asio::async_read(socket_, boost::asio::buffer(&readHeader_, sizeof(uint32_t)),
        [this](boost::system::error_code ec, std::size_t length) {
            if (!ec) {
                uint32_t packetSize = 0;
                std::memcpy(&packetSize, &readHeader_, sizeof(uint32_t));

                // Step 2: Resize the read buffer to the size of the packet
                //std::cout << "Packet size: " << packetSize << std::endl;

                // Step 3: Read the packet data
                boost::asio::async_read(socket_, boost::asio::buffer(readMsg_, packetSize), 
                    [this](boost::system::error_code ec, std::size_t length) {
                        if (!ec) {
                            std::vector<uint8_t> vec;
                            vec.reserve(length);
                            // Display all bits in readMsg_
                            for (int i = 0; i < length; i++) {
                                vec.push_back(readMsg_[i]);
                            }

                            //std::cout << std::endl;

                            SCServer::Packet packet(SCServer::PacketVersion::V0, vec);

                            //std::cout << "Received packet version: " << (int)packet.packetVersion << " of " << (int)packet.packetID << std::endl;

                            readMsg_ = new uint8_t[SCServer::Packet::MAX_PACKET_SIZE];

                            switch (packet.packetID) {
                                case SCServer::PacketID::ECHO: {
                                    std::cout << "Client " << (int)packet.packetSender << " sent: " << packet.DeserializeString() << std::endl;
                                    break;
                                }
                                case SCServer::PacketID::DELIVER: {
                                    std::cout << "Deliver received:" << std::endl;
                                    id = packet.DeserializeUInt8();
                                    std::cout << "Client ID is now " << (int)id << std::endl;
                                    break;
                                }
                                case SCServer::PacketID::UPDATE: {
                                    float dt = packet.DeserializeFloat();
                                    //std::cout << "Server delta time: " << dt << std::endl;
                                    break;
                                }
                            }

                            ReadPacket();
                        }
                    });
            }
        });
}

void Client::WritePacket() {
    // Step 1: Serialize the packet
    uint32_t packetSize = (uint32_t)writeMessages_.front().ToVec().size();

    // Step 2: Prepare a buffer for header + data
    buffer = std::vector<uint8_t>(sizeof(uint32_t) + packetSize);
    std::memcpy(buffer.data(), &packetSize, sizeof(uint32_t));
    std::memcpy(buffer.data() + sizeof(uint32_t), writeMessages_.front().ToBytes(), packetSize);

    //std::cout << "Sending: " << (int)writeMessages_.front().packetVersion << " of " << (int)writeMessages_.front().packetID << " from " << (int)writeMessages_.front().packetSender << std::endl;
    //std::cout << "The buffer is " << buffer.size() << " bytes long" << std::endl;
    //std::cout << "The data is " << packetSize << " bytes long" << std::endl;

    boost::asio::async_write(socket_, boost::asio::buffer(buffer),
        [this](boost::system::error_code ec, std::size_t /*length*/) {
            if (!ec) {
                writeMessages_.pop_front();
                if (!writeMessages_.empty()) {
                    WritePacket();
                }
            }
        });
}