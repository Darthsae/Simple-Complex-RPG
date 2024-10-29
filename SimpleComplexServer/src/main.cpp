#include <iostream>
#include "simple_complex_rpg/server/server.h"
#include "simple_complex_rpg/server/server_config.h"
#include <chrono>
#include <thread>
#include <atomic>
#include <sago/platform_folders.h>

using SimpleComplexRPG::Server::ServerConfig;

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

    // Launch a separate thread to handle console input
    std::thread inputThread([&]() {
        std::string command;
        while (!quit) {
            std::getline(std::cin, command);

            // TODO: Refine commands to be some type of data structure that can make procesing and integration easier.

            // Process the command
            // Trim leading and trailing whitespace
            command = command.substr(command.find_first_not_of(" \t\r\n"));
            if (command.length() == 0) {
                continue;
            }
            command = command.substr(0, command.find_last_not_of(" \t\r\n") + 1);

            // Split the command by whitespace
            std::vector<std::string> tokens;
            std::string token;
            std::istringstream tokenStream(command);
            while (std::getline(tokenStream, token, ' ')) {
                tokens.push_back(token);
            }

            // Process the initializer
            std::string initializer = tokens[0];
            tokens.erase(tokens.begin());

            if (initializer == "quit") { // Quit command, no arguments
                quit = true;
            } else if (initializer == "help") { // Help command, no arguments
                std::cout << "Available commands:" << std::endl;

                // TODO: Unhardcode this once swapping command data structure is implemented
                std::cout << "  quit" << std::endl;
                std::cout << "  help" << std::endl;
            } else { // Unknown command
                std::cout << "Unknown initializer: " << initializer << std::endl;
                continue;
            }
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
