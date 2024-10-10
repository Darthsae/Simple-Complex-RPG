#include "simple_complex_rpg/client/client.h"
#include <iostream>

using namespace SimpleComplexRPG::Client;

void Client::deliver(const SCServer::Packet& msg)
{
    std::cout << "Packet with ID " << msg.packet_id << " recieved." << std::endl;
}