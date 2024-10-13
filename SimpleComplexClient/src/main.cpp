#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <string>
#include "simple_complex_rpg/client/client.h"
#include "simple_complex_rpg/server/packet.h"

using namespace SimpleComplexRPG::Client;

namespace SCServer = SimpleComplexRPG::Server;

int main(int, char**){
    std::cout << "Hello, from SimpleComplexRPG!\n";
    std::string host = "localhost";
    std::string port = "12345";

    boost::asio::io_context io_context;
    tcp::resolver resolver(io_context);
    auto endpoints = resolver.resolve(host, port);
    Client client(io_context, endpoints);

    boost::thread t([&io_context]() { io_context.run(); });

    std::string line;
    while (std::getline(std::cin, line)) {
        if (line == "quit") {
            break;
        }
        else if (line.substr(0, 5) == "echo ") {
            std::string msg = line.substr(5);
            SCServer::Packet packet(SCServer::PacketVersion::V0, SCServer::PacketID::ECHO);
            packet.packet_sender = client.get_id();
            packet.serialize(msg);
            client.write(packet);
            std::cout << "Sent: " << (int)packet.packet_version << " of " << (int)packet.packet_id << std::endl;
        }
    }

    client.close();
    t.join();
    return 0;
}
