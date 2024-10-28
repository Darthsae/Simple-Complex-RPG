#ifndef SPRITE_H
#define SPRITE_H
#include <memory>
#include "dei_voluntas/graphics/texture.h"

namespace DeiVoluntas::Graphics {
    struct Sprite {
        Texture* texture;

        Sprite();
        Sprite(Texture* texture);
        ~Sprite();
    };
}
#endif