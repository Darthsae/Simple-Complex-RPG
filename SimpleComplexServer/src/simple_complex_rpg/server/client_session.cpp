#include "simple_complex_rpg/server/client_session.h"
#include <bitset>

using namespace SimpleComplexRPG::Server;

std::vector<std::shared_ptr<ClientSession>> ClientSession::Participants;

ClientSession::ClientSession(tcp::socket socket) : socket_(std::move(socket)) {
    readMsg_ = new uint8_t[Packet::MAX_PACKET_SIZE];
}

void ClientSession::Start(uint8_t id) {
    this->id = id;
    std::cout << "Client " << (int)id << " connected" << std::endl;
    ReadPacket();
}

void ClientSession::Deliver(const Packet& message) {
    bool writeInProgress = !writeMessages_.empty();
    writeMessages_.push_back(message);
    if (!writeInProgress) {
        SendPacket();
    }
}

void ClientSession::ReadPacket() {
    auto self(shared_from_this());

    boost::asio::async_read(socket_, boost::asio::buffer(&readHeader_, sizeof(uint32_t)),
        [this, self](boost::system::error_code ec, std::size_t length) {
            uint32_t packetSize = 0;
            std::memcpy(&packetSize, &readHeader_, sizeof(uint32_t));

            // Step 2: Resize the read buffer to the size of the packet
            //std::cout << "Packet size: " << packetSize << std::endl;

            boost::asio::async_read(socket_, boost::asio::buffer(readMsg_, packetSize),
                [this, self](boost::system::error_code ec, std::size_t length) {
                    if (!ec) {
                        std::vector<uint8_t> vec;
                        vec.reserve(length);
                        // Display all bits in readMsg_
                        for (int i = 0; i < length; i++) {
                            vec.push_back(readMsg_[i]);
                        }

                        //std::cout << std::endl;

                        Packet packet(PacketVersion::V0, vec);
                        //std::cout << "Packet size: " << length << std::endl;
                        //std::cout << "Received packet version: " << (int)packet.packetVersion << " of " << (int)packet.packetID << std::endl;

                        readMsg_ = new uint8_t[Packet::MAX_PACKET_SIZE];

                        switch (packet.packetID) {
                            case PacketID::SYNC: {
                                //std::cout << "Sync received" << std::endl;
                                // Broadcast to all clients
                                for (auto& participant : Participants) {
                                    participant->Deliver(packet);
                                }
                                break;
                            }
                            case PacketID::ECHO: {
                                //std::cout << "Echo received from client " << (int)packet.packetSender << std::endl;
                                // Broadcast to all clients
                                for (auto& participant : Participants) {
                                    if (participant->GetID() != packet.packetSender) participant->Deliver(packet);
                                }
                                break;
                            }
                            case PacketID::QUIT: {
                                std::cout << "Client " << (int)packet.packetSender << " disconnected, resyncing all clients" << std::endl;
                                Participants.erase(Participants.begin() + packet.packetSender - 1);

                                // Broadcast to all clients
                                uint8_t i = 0;
                                for (auto& participant : Participants) {
                                    i++;
                                    Packet resync(PacketVersion::V0, PacketID::SYNC);
                                    resync.packetSender = 0;
                                    resync.Serialize(i);
                                    participant->Deliver(resync);
                                }
                                break;
                            }
                        }

                        ReadPacket();
                    }
                });
        });
    
}

void ClientSession::SendPacket() {
    auto self(shared_from_this());
    // Step 1: Serialize the packet
    uint32_t packetSize = (uint32_t)writeMessages_.front().ToVec().size();

    // Step 2: Prepare a buffer for header + data
    buffer = std::vector<uint8_t>(sizeof(uint32_t) + packetSize);
    std::memcpy(buffer.data(), &packetSize, sizeof(uint32_t));
    std::memcpy(buffer.data() + sizeof(uint32_t), writeMessages_.front().ToBytes(), packetSize);

    //std::cout << "Sending: " << (int)writeMessages_.front().packetVersion << " of " << (int)writeMessages_.front().packetID << std::endl;
    //std::cout << "The buffer is " << buffer.size() << " bytes long" << std::endl;
    //std::cout << "The data is " << packetSize << " bytes long" << std::endl;

    boost::asio::async_write(socket_, boost::asio::buffer(buffer),
        [this, self](boost::system::error_code ec, std::size_t /*length*/) {
            if (!ec) {
                writeMessages_.pop_front();
                if (!writeMessages_.empty()) {
                    SendPacket();
                }
            }
        });
}