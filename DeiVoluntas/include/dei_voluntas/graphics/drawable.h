/**
 * @file drawable.h
 * @brief Defines the Drawable struct, which represents renderable properties for an entity.
 */

#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "dei_voluntas/data/circle.h"
#include <SDL.h>

/**
 * @namespace DeiVoluntas::Graphics
 * @brief Contains classes and structs related to rendering in the DeiVoluntas engine.
 */
namespace DeiVoluntas::Graphics {
    /**
     * @struct Drawable
     * @brief Represents an entity that can be rendered with a specific color.
     *
     * The `Drawable` struct defines the color properties used to render an entity on the screen.
     */
    struct Drawable {
        /**
         * @brief Default constructor for Drawable.
         *
         * Initializes the color to a default value.
         */
        Drawable();

        /**
         * @brief Constructs a Drawable with a specified SDL_Color.
         *
         * @param color The SDL_Color to set for this Drawable.
         */
        Drawable(const SDL_Color& color);

        /**
         * @brief Constructs a Drawable with specific color components.
         *
         * @param r The red component of the color.
         * @param g The green component of the color.
         * @param b The blue component of the color.
         * @param a The alpha (transparency) component of the color.
         */
        Drawable(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

        SDL_Color color; ///< The color used to render the Drawable.
    };
}

#endif
