#include "dei_voluntas/graphics/sprite.h"
#include <iostream>

using namespace DeiVoluntas::Graphics;

Sprite::Sprite() {}

Sprite::Sprite(Texture* texture) : texture(texture) {
    //std::cout << "Sprite: " << texture.size.x << ", " << texture.size.y << std::endl;
}

Sprite::~Sprite() {
    std::cout << "Sprite destroyed" << std::endl;
}