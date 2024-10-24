#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "simple_complex_rpg/client/client.h"
#include "simple_complex_rpg/server/packet.h"
#include <dei_voluntas/scene.h>
#include <dei_voluntas/physics/rigid_body.h>
#include <dei_voluntas/physics/transform.h>
#include <dei_voluntas/graphics/drawable.h>
#include <dei_voluntas/data/circle.h>
#include <random>

using namespace SimpleComplexRPG::Client;

namespace SCServer = SimpleComplexRPG::Server;

namespace ECS = DeiVoluntas::ECS;
namespace Physics = DeiVoluntas::Physics::DeiVoluntas;
namespace Graphics = DeiVoluntas::Graphics;
namespace Data = DeiVoluntas::Data;

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

    SDL_Window *window = SDL_CreateWindow("Simple Complex RPG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    DeiVoluntas::Scene scene();

    std::default_random_engine generator;
    std::uniform_real_distribution<float> xPositionDistribution(0.0f, 800.0f);
    std::uniform_real_distribution<float> yPositionDistribution(0.0f, 600.0f);
    std::uniform_real_distribution<float> velocityDistribution(-10.0f, 10.0f);
    std::uniform_real_distribution<float> radiusDistribution(1.0f, 5.0f);
    std::uniform_int_distribution<uint16_t> colorDistribution(0, 255);

    int testingEntities = 4500;

    for (int i = 0; i < testingEntities; i++) {
        scene.CreateEntity();
    }

    float dt = 0.0f;
    float playerSpeed = 10.0f;
    const uint8_t* keyboardState;

    while (!quit) {
        auto startTime = std::chrono::high_resolution_clock::now();

        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_BACKQUOTE:
                        quit = true;
                        break;
                }
            }
        }

        #pragma region Keyboard Input Held
        keyboardState = SDL_GetKeyboardState(nullptr);

        if (keyboardState[SDL_SCANCODE_W]) {
            scene.cameraPosition.y -= 10;
        }

        if (keyboardState[SDL_SCANCODE_S]) {
            scene.cameraPosition.y += 10;
        }

        if (keyboardState[SDL_SCANCODE_A]) {
            scene.cameraPosition.x -= 10;
        }

        if (keyboardState[SDL_SCANCODE_D]) {
            scene.cameraPosition.x += 10;
        }
        #pragma endregion

        scene.Update(dt);

        SDL_RenderClear(renderer);
        scene.Draw(renderer);
        SDL_RenderPresent(renderer);

        auto stopTime = std::chrono::high_resolution_clock::now();

		dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();
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
