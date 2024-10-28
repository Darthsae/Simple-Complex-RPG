/**
 * @file texture.h
 * @brief Defines the Texture struct, which encapsulates texture data for rendering in the DeiVoluntas engine.
 */

#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL.h>
#include <string>
#include "dei_voluntas/data/vec.h"

using DeiVoluntas::Data::Vec2i;

/**
 * @namespace DeiVoluntas::Graphics
 * @brief Contains classes and structs related to rendering in the DeiVoluntas engine.
 */
namespace DeiVoluntas::Graphics {
    /**
     * @struct Texture
     * @brief Represents a texture loaded from an image file for rendering.
     *
     * The `Texture` struct holds information about the texture's size, name, and SDL-specific data required for rendering.
     */
    struct Texture {
        /**
         * @brief Default constructor for Texture.
         *
         * Initializes an empty Texture with no associated SDL resources.
         */
        Texture();

        /**
         * @brief Constructs a Texture by loading an image from a file path.
         *
         * @param renderer Pointer to the SDL_Renderer used for creating the texture.
         * @param path Path to the image file to load as a texture.
         */
        Texture(SDL_Renderer* renderer, std::string path);

        /**
         * @brief Destructor for Texture.
         *
         * Cleans up associated SDL resources (surface and texture).
         */
        ~Texture();

        std::string name; ///< Name of the texture, typically the file name or a unique identifier. 

        SDL_Surface* surface; ///< SDL surface representing the texture image data. 
        SDL_Texture* texture; ///< SDL texture used for rendering. 

        Vec2i size; ///< Size of the texture in pixels. 
    };
}

#endif
