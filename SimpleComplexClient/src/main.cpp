#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "simple_complex_rpg/client/client.h"
#include "simple_complex_rpg/server/packet.h"
#include "dei_voluntas/scene.h"

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

    bool quit = false;
    SDL_Event event;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
        std::cerr << "IMG_Init Error: " << IMG_GetError() << std::endl;
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("TCreator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    DeiVoluntas::Scene scene(DeiVoluntas::SceneFlags::DEI_VOLUNTAS_PHYSICS | DeiVoluntas::SceneFlags::SDL2_GRAPHICS);

    while (!quit) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_w) {
                    scene.cameraPosition.y -= 10;
                }
                else if (event.key.keysym.sym == SDLK_s) {
                    scene.cameraPosition.y += 10;
                }
                else if (event.key.keysym.sym == SDLK_a) {
                    scene.cameraPosition.x -= 10;
                }
                else if (event.key.keysym.sym == SDLK_d) {
                    scene.cameraPosition.x += 10;
                }
            }
        }

        SDL_RenderClear(renderer);
        scene.Draw(renderer);
        SDL_RenderPresent(renderer);
    }

    /*
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
    */

    scene.~Scene();

    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    client.close();
    t.join();
    return 0;
}
