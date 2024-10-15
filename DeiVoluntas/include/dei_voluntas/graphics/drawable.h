#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "dei_voluntas/data/circle.h"
#include <SDL.h>

namespace DeiVoluntas::Graphics {
    struct Drawable {
        Drawable();
        Drawable(const SDL_Color& color);
        Drawable(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

        SDL_Color color;
    };
}

#endif