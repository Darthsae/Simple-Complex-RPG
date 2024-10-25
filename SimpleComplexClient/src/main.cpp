#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "simple_complex_rpg/client/client.h"
#include "simple_complex_rpg/server/packet.h"
#include <dei_voluntas/scene.h>
#include <dei_voluntas/physics/rigid_body.h>
#include <dei_voluntas/physics/transform.h>
#include <dei_voluntas/graphics/drawable.h>
#include <dei_voluntas/data/circle.h>
#include <random>
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>

using namespace SimpleComplexRPG::Client;

namespace SCServer = SimpleComplexRPG::Server;

namespace Physics = DeiVoluntas::Physics;
namespace Graphics = DeiVoluntas::Graphics;
namespace Data = DeiVoluntas::Data;

enum UIState {
    MAIN_MENU,
    GAME,
    TEMP,
};

const float X_POS = 0.0f;
const float Y_POS = 0.0f;
const FLOAT X_SIZE = 8000.0f;
const FLOAT Y_SIZE = 8000.0f;
const float MIN_RADIUS = 1.0f;
const float MAX_RADIUS = 25.0f;
const float MAX_VELOCITY = 50.0f;

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

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGui::StyleColorsDark();

    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer); 
    ImGui_ImplSDLRenderer2_Init(renderer);

    UIState currentUIState = UIState::TEMP;

    DeiVoluntas::Scene scene = DeiVoluntas::Scene(0, Vec2f((X_SIZE / 2.0f + 400.0f) - X_POS, (Y_SIZE / 2.0f + 300.0f) - Y_POS), Vec2f(800.0f, 600.0f), Vec2f(X_POS, Y_POS), Vec2f(X_SIZE, Y_SIZE));

    std::default_random_engine generator;
    std::uniform_real_distribution<float> xPositionDistribution(X_POS + MAX_RADIUS, X_SIZE - X_POS - MAX_RADIUS);
    std::uniform_real_distribution<float> yPositionDistribution(Y_POS + MAX_RADIUS, Y_SIZE - Y_POS - MAX_RADIUS);
    std::uniform_real_distribution<float> velocityDistribution(-MAX_VELOCITY, MAX_VELOCITY);
    std::uniform_real_distribution<float> radiusDistribution(MIN_RADIUS, MAX_RADIUS);
    std::uniform_int_distribution<uint16_t> colorDistribution(0, 255);

    int testingEntities = 1000;

    for (int i = 0; i < testingEntities; i++) {
        Vec2f position = Vec2f(xPositionDistribution(generator), yPositionDistribution(generator));
        SDL_Color color = SDL_Color { (uint8_t)colorDistribution(generator), (uint8_t)colorDistribution(generator), (uint8_t)colorDistribution(generator), (uint8_t)colorDistribution(generator) };
        b2CircleShape shape = b2CircleShape();
        shape.m_radius = radiusDistribution(generator);
        Vec2f velocity = Vec2f(velocityDistribution(generator), velocityDistribution(generator));
        scene.CreateEntity(position, color, shape, b2_dynamicBody, 1.0f, 0.0f, 1.0f, 0.0f, velocity, 0.0f, 0.0f, 0.0f, false);
    }

    b2EdgeShape edge = b2EdgeShape();
    edge.SetTwoSided(b2Vec2(X_POS, Y_POS), b2Vec2(X_POS, Y_SIZE));
    scene.CreateEntity(Vec2f::ZERO, SDL_Color { 255, 255, 255, 255 }, edge, b2_staticBody, 1.0f, 0.0f, 0.0f, 0.0f, Vec2f::ZERO, 0.0f, 0.0f, 0.0f, true);

    edge.SetTwoSided(b2Vec2(X_POS, Y_SIZE), b2Vec2(X_SIZE, Y_SIZE));
    scene.CreateEntity(Vec2f::ZERO, SDL_Color { 255, 255, 255, 255 }, edge, b2_staticBody, 1.0f, 0.0f, 0.0f, 0.0f, Vec2f::ZERO, 0.0f, 0.0f, 0.0f, true);

    edge.SetTwoSided(b2Vec2(X_SIZE, Y_SIZE), b2Vec2(X_SIZE, Y_POS));
    scene.CreateEntity(Vec2f::ZERO, SDL_Color { 255, 255, 255, 255 }, edge, b2_staticBody, 1.0f, 0.0f, 0.0f, 0.0f, Vec2f::ZERO, 0.0f, 0.0f, 0.0f, true);

    edge.SetTwoSided(b2Vec2(X_SIZE, Y_POS), b2Vec2(X_POS, Y_POS));
    scene.CreateEntity(Vec2f::ZERO, SDL_Color { 255, 255, 255, 255 }, edge, b2_staticBody, 1.0f, 0.0f, 0.0f, 0.0f, Vec2f::ZERO, 0.0f, 0.0f, 0.0f, true);

    float dt = 0.0f;
    float playerSpeed = 1.0f;
    const uint8_t* keyboardState;

    const int RECENT_COUNT = 20;

    float recent[RECENT_COUNT];

    for (int i = 0; i < RECENT_COUNT; i++) {
        recent[i] = 0.0f;
    }

    int recentIndex = 0;

    while (!quit) {
        auto startTime = std::chrono::high_resolution_clock::now();

        while (SDL_PollEvent(&event) != 0) {
            ImGui_ImplSDL2_ProcessEvent(&event);
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
            scene.cameraPosition.y += 10;
        }

        if (keyboardState[SDL_SCANCODE_S]) {
            scene.cameraPosition.y -= 10;
        }

        if (keyboardState[SDL_SCANCODE_A]) {
            scene.cameraPosition.x += 10;
        }

        if (keyboardState[SDL_SCANCODE_D]) {
            scene.cameraPosition.x -= 10;
        }
        #pragma endregion

        scene.Update(dt);

        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        switch (currentUIState) {
            case UIState::TEMP:
                ImGui::Begin("Debug", (bool*)0, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar);
                ImGui::SetWindowPos(ImVec2(0, 0));
                ImGui::SetWindowSize(ImVec2(124, 32));

                float sum = 0;

                for (int i = 0; i < RECENT_COUNT; i++) {
                    sum += recent[i];
                }
                
                ImGui::Text(("FPS: " + std::to_string((int)(RECENT_COUNT / sum))).c_str());

                ImGui::End();
                break;
        }

        ImGui::Render();
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        scene.Draw(renderer);
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), renderer);
        SDL_RenderPresent(renderer);

        auto stopTime = std::chrono::high_resolution_clock::now();

		dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();

        recent[recentIndex] = dt;
        recentIndex = (recentIndex + 1) % RECENT_COUNT;
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

    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    client.close();
    t.join();
    return 0;
}
