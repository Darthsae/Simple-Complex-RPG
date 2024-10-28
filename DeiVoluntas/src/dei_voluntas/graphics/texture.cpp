#include "dei_voluntas/graphics/texture.h"
#include <SDL_image.h>
#include <iostream>

using namespace DeiVoluntas::Graphics;

Texture::Texture() {
    name = "null";
    texture = nullptr;
    size = Vec2i(0, 0);
}

Texture::Texture(SDL_Renderer* renderer, std::string path) {
    std::cout << path << std::endl;
    surface = IMG_Load(path.c_str());
    if (surface == nullptr) {
        std::cerr << "Failed to load image: " << path << " - " << IMG_GetError() << std::endl;
        texture = nullptr;
        size = Vec2i(0, 0);
        return;
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == nullptr) {
        std::cerr << "Failed to create texture from surface: " << SDL_GetError() << std::endl;
        size = Vec2i(0, 0);
        SDL_FreeSurface(surface);
        surface = nullptr;
        return;
    }

    size = Vec2i(surface->w, surface->h);

    name = path;
}

Texture::~Texture() {
    std::cout << "Texture destroyed: " << name << std::endl;
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}
