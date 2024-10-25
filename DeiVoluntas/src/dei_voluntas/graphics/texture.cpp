#include "dei_voluntas/graphics/texture.h"
#include <SDL_image.h>

using namespace DeiVoluntas::Graphics;

Texture::Texture(SDL_Renderer* renderer, std::string path) {
    SDL_Surface *surface = IMG_Load(path.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    size = Vec2i(surface->w, surface->h);
    SDL_FreeSurface(surface);
}

Texture::~Texture() {
    SDL_DestroyTexture(texture);
}
