/**
 * @file sprite.h
 * @brief Defines the Sprite struct, which represents a renderable texture for an entity.
 */

#ifndef SPRITE_H
#define SPRITE_H
#include <memory>
#include "dei_voluntas/graphics/texture.h"

/**
 * @namespace DeiVoluntas::Graphics
 * @brief Contains classes and structs related to rendering in the DeiVoluntas engine.
 */
namespace DeiVoluntas::Graphics {
    /**
     * @struct Sprite
     * @brief Represents an entity with a texture that can be rendered.
     *
     * The `Sprite` struct holds a pointer to a `Texture` object that defines the image used
     * for rendering the entity.
     */
    struct Sprite {
        /**
         * @brief Default constructor for Sprite.
         *
         * Initializes the Sprite without a texture.
         */
        Sprite();

        /**
         * @brief Constructs a Sprite with a specified texture.
         *
         * @param texture Pointer to the Texture to set for this Sprite.
         */
        Sprite(Texture* texture);

        /**
         * @brief Destructor for Sprite.
         *
         * Handles any cleanup necessary for the texture.
         */
        ~Sprite();

        Texture* texture; ///< Pointer to the texture used for rendering the Sprite.
    };
}

#endif
