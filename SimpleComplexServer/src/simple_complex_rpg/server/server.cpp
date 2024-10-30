#include "simple_complex_rpg/server/server.h"
#include <iostream>

using namespace SimpleComplexRPG::Server;

Packet CreateUpdatePacket(const Server& server, const float& dt) {
    Packet packet(PacketVersion::V0, PacketID::UPDATE);

    packet.Serialize(dt);

    return packet;
}

Server::Server(boost::asio::io_context& io_context, int16_t port) : acceptor_(io_context, tcp::endpoint(tcp::v4(), port)) {
    std::cout << "Initializing server..." << std::endl;
    AcceptConnection();
}

void Server::Update(float dt) {
    Packet packet = CreateUpdatePacket(*this, dt);
    WriteToAllClients(packet);
}

void Server::WriteToClient(uint8_t id, const Packet& message) {
    if (id >= ClientSession::Participants.size() || id < 0) {
        std::cout << "Invalid client ID: " << id << std::endl;
        return;
    }

    ClientSession::Participants[id]->Deliver(message);
}

void Server::WriteToAllClients(const Packet& message) {
    for (auto& session : ClientSession::Participants) {
        session->Deliver(message);
    }
}

void Server::AcceptConnection() {
    acceptor_.async_accept(
        [this](boost::system::error_code ec, tcp::socket socket) {
            if (!ec) {
                std::cout << "Accepted connection" << std::endl;
                auto session = std::make_shared<ClientSession>(std::move(socket));
                ClientSession::Participants.push_back(session);
                session->Start((uint8_t)ClientSession::Participants.size());

                // Inform client of it's ID
                Packet packet(PacketVersion::V0, PacketID::DELIVER);
                packet.packetSender = 0;
                packet.Serialize((uint8_t)ClientSession::Participants.size());
                session->Deliver(packet);
            }
            AcceptConnection();
        });
}