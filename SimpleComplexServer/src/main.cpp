#include <iostream>
#include "simple_complex_rpg/server/server.h"
#include <chrono>

int main(int, char**){
    boost::asio::io_context io_context;
    SimpleComplexRPG::Server::Server server(io_context, 12345);
    bool quit = false;
    float dt = 0.0f;
    while (!quit){
        auto startTime = std::chrono::high_resolution_clock::now();

        io_context.poll();

        server.Update(dt);

        auto stopTime = std::chrono::high_resolution_clock::now();

		dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();
    }
    return 0;
}
