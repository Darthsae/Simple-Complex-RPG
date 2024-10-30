#include <iostream>
#include "simple_complex_rpg/server/server.h"
#include "simple_complex_rpg/server/server_config.h"
#include <chrono>
#include <thread>
#include <atomic>
#include <sago/platform_folders.h>
#include <simple_complex_rpg/common/command_handler.h>

using SimpleComplexRPG::Server::ServerConfig;
using SimpleComplexRPG::Common::CommandHandler;
using SimpleComplexRPG::Common::Command;
using SimpleComplexRPG::Common::Parameter;
using SimpleComplexRPG::Common::ParameterType;

int main(int, char**){
    boost::asio::io_context io_context;

    #pragma region Directories
    std::string dataDirectory = sago::getDataHome() + "/SimpleComplexRPG/";
    std::string saveDirectory = sago::getSaveGamesFolder1() + "/SimpleComplexRPG/";

    if (!std::filesystem::exists(dataDirectory)) {
        std::filesystem::create_directories(dataDirectory);
    }

    if (!std::filesystem::exists(saveDirectory)) {
        std::filesystem::create_directories(saveDirectory);
    }
    #pragma endregion

    std::cout << "Starting server..." << std::endl;
    ServerConfig config = ServerConfig::Load(saveDirectory + "server_config.config");

    // Start the server
    SimpleComplexRPG::Server::Server server(io_context, 12345);
    std::atomic<bool> quit{false};
    float dt = 0.0f;

    #pragma region Commands
    CommandHandler commandHandler = CommandHandler();
    commandHandler.AddCommand(Command("quit", "Quits the server.", [&](const CommandHandler& handler, std::vector<Parameter>& parameters) {
        quit = true;
    }));

    commandHandler.AddCommand(Command("help", [&](const CommandHandler& handler, const std::vector<Parameter>& parameters) {
        std::cout << "Available commands:" << std::endl;
        for (Command command : handler.commands) {
            std::cout << "\t" << command.name << ": " << command.description << std::endl;
        }
    }));

    commandHandler.AddCommand(Command("force_disconnect", [&](const CommandHandler& handler, const std::vector<Parameter>& parameters) {
        SimpleComplexRPG::Server::Packet packet = SimpleComplexRPG::Server::Packet(SimpleComplexRPG::Server::PacketVersion::V0, SimpleComplexRPG::Server::PacketID::KICK);
        if (parameters.size() >= 2 && parameters[1].index() == 2) {
            packet.Serialize(std::get<std::string>(parameters[1]));
        } else {
            std::cout << "Expected string for reason but got a different type." << std::endl;
            packet.Serialize("No reason given");
        }
        if (parameters.size() > 0) {
            if (parameters[0].index() == 0) {  // Assuming index 1 corresponds to `int`
                std::cout << "Force disconnecting client with ID: " << std::get<int>(parameters[0]) << std::endl;
                int clientID = std::get<int>(parameters[0]);
                server.WriteToClient(clientID, packet);
            } else {
                std::cout << "Expected integer for client ID but got a different type." << std::endl;
            }
        } else {
            std::cout << "No parameters provided for force_disconnect command." << std::endl;
        }
    }));

    commandHandler.commands[commandHandler.commands.size() - 1].AddParameter(ParameterType::INT);
    commandHandler.commands[commandHandler.commands.size() - 1].AddParameter(ParameterType::STRING);

    //commandHandler.AddCommand(Command("", [&](const CommandHandler& handler, std::vector<Parameter> parameters) {}));

    commandHandler.AddCommand(Command("", [&](const CommandHandler& handler, const std::vector<Parameter>& parameters) {}));
    #pragma endregion

    // Launch a separate thread to handle console input
    std::thread inputThread([&]() {
        std::string command;
        while (!quit) {
            std::getline(std::cin, command);

            // Process the command
            // Trim leading and trailing whitespace
            command = command.substr(command.find_first_not_of(" \t\r\n"));
            if (command.length() == 0) {
                continue;
            }
            command = command.substr(0, command.find_last_not_of(" \t\r\n") + 1);

            // Split the command by whitespace
            std::vector<Parameter> tokens;
            std::string token;
            std::istringstream tokenStream(command);
            Command::Tokenize(tokenStream, tokens);

            // Process the initializer
            std::string initializer = std::get<std::string>(tokens[0]);
            tokens.erase(tokens.begin());

            commandHandler.ExecuteCommand(initializer, tokens);
        }
    });

    while (!quit){
        auto startTime = std::chrono::high_resolution_clock::now();

        io_context.poll();

        server.Update(dt);

        auto stopTime = std::chrono::high_resolution_clock::now();

		dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();
    }

    // Clean up
    if (inputThread.joinable()) {
        inputThread.join();
    }

    std::cout << "Shutting down server..." << std::endl;
    config.Save(saveDirectory + "server_config.config");

    return 0;
}
