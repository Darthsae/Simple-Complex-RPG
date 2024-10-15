#include "dei_voluntas/graphics/drawable.h"

using namespace DeiVoluntas::Graphics;

Drawable::Drawable() : color({255, 255, 255, 255}) {}

Drawable::Drawable(const SDL_Color& color) : color(color) {}

Drawable::Drawable(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : color({r, g, b, a}) {}