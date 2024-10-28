#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL.h>
#include <string>
#include "dei_voluntas/data/vec.h"

using DeiVoluntas::Data::Vec2i;

namespace DeiVoluntas::Graphics {
    struct Texture {
        Texture();
        Texture(SDL_Renderer* renderer, std::string path);
        ~Texture();

        std::string name;

        SDL_Surface* surface;
        SDL_Texture* texture;

        Vec2i size;
    };
}
#endif
