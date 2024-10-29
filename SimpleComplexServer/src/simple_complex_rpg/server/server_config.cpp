#include "simple_complex_rpg/server/server_config.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <simple_complex_rpg/server/packet.h>

using namespace SimpleComplexRPG::Server;

ServerConfig ServerConfig::Load(const std::filesystem::path& path) {
    std::ifstream file(path, std::ios::binary | std::ios::ate);  // Open the file in binary mode and seek to the end

    if (!file.is_open()) { // Check if the file was opened successfully
        std::cerr << "Failed to open server configuration file: " << path << std::endl;
        ServerConfig config;
        config.ToDefaults(); 
        return config;
    }
    

    std::streamsize size = file.tellg();  // Get the size of the file
    file.seekg(0, std::ios::beg);         // Return to the beginning of the file
    
    std::vector<std::uint8_t> buffer(size); // Allocate buffer of appropriate size
    if (!file.read(reinterpret_cast<char*>(buffer.data()), size)) {
        std::cerr << "Failed to read the complete file: " << path << std::endl;
        ServerConfig config;
        config.ToDefaults(); 
        return config;
    }

    file.close();

    Packet packet(SimpleComplexRPG::Server::PacketVersion::V0, buffer); // Use the Packet class to deserialize the buffer, due to the packet class already having serialization implemented.

    ServerConfig config;  // Create a new ServerConfig instance
    config.name = path.stem().string();

    return config;
}

ServerConfig ServerConfig::Load(const std::string& path) {
    return Load(std::filesystem::path(path));
}

void ServerConfig::Save(const std::filesystem::path& path) {
    std::ofstream file(path, std::ios::binary | std::ios::trunc);  // Open the file in binary mode and truncate the file

    if (!file.is_open()) { // Check if the file was opened successfully
        std::cerr << "Failed to open server configuration file: " << path << std::endl;
        return;
    }

    Packet packet(SimpleComplexRPG::Server::PacketVersion::V0, SimpleComplexRPG::Server::PacketID::CONFIG); // Use the Packet class to serialize the ServerConfig instance
    packet.packetSender = 0;  // Set the packet sender to 0, which is the server's ID (I think?)

    // Serialize the ServerConfig instance into the packet
    packet.Serialize(this->name);
    packet.Serialize(this->maxClients);

    std::vector<std::uint8_t> buffer = packet.ToVec();  // Convert the packet to a vector of bytes to write to the file

    file.write(reinterpret_cast<char*>(buffer.data()), buffer.size());  // Write the serialized data to the file
    file.close();  // Close the file

    std::cout << "Server configuration saved to: " << path << std::endl;
}

void ServerConfig::Save(const std::string& path) {
    Save(std::filesystem::path(path));
}

void ServerConfig::ToDefaults() {
    this->name = "";
    this->maxClients = 0;
}