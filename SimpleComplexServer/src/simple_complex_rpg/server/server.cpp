#include "simple_complex_rpg/server/server.h"
#include <iostream>

using namespace SimpleComplexRPG::Server;

Server::Server(boost::asio::io_context& io_context, int16_t port) : acceptor_(io_context, tcp::endpoint(tcp::v4(), port)) {
    std::cout << "Initializing server..." << std::endl;
    acceptConnection();
}

void Server::run() {
}

void Server::acceptConnection() {
    acceptor_.async_accept(
        [this](boost::system::error_code ec, tcp::socket socket) {
            if (!ec) {
                std::cout << "Accepted connection" << std::endl;
                auto session = std::make_shared<ClientSession>(std::move(socket));
                ClientSession::participants.push_back(session);
                session->start((uint8_t)ClientSession::participants.size());

                // Inform client of it's ID
                Packet packet(PacketVersion::V0, PacketID::DELIVER);
                packet.packet_sender = 0;
                packet.serialize((uint8_t)ClientSession::participants.size());
                session->deliver(packet);
            }
            acceptConnection();
        });
}