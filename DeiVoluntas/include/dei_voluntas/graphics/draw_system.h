/**
 * @file draw_system.h
 * @brief Defines the DrawSystem class, which manages drawing entities in the DeiVoluntas game engine.
 */

#ifndef DRAW_SYSTEM_H
#define DRAW_SYSTEM_H
#include "dei_voluntas/data/vec.h"
#include <SDL.h>
#include <vector>
#include "dei_voluntas/data/quadtree.h"
#include <entt/entt.hpp>

using DeiVoluntas::Data::Vec2f;
using DeiVoluntas::Data::Quadtree;

/**
 * @namespace DeiVoluntas::Graphics
 * @brief Contains classes and functions related to rendering in the DeiVoluntas engine.
 */
namespace DeiVoluntas::Graphics {
    /**
     * @class DrawSystem
     * @brief Manages the rendering of entities within a specific area.
     *
     * The `DrawSystem` class handles rendering entities onto the screen
     * based on their positions and scales, utilizing a quadtree for efficient spatial partitioning.
     */
    class DrawSystem {
    public:
        /**
         * @brief Draws entities within the specified position and scale range.
         *
         * This function uses the quadtree to efficiently determine which entities are
         * within the viewport and then renders them using the SDL renderer.
         *
         * @param position The position to center the drawing around.
         * @param scale The scale factor for drawing entities.
         * @param registry The entity registry containing all components and entities.
         * @param quadtree The quadtree for spatial partitioning and quick entity lookup.
         * @param renderer The SDL renderer used for rendering.
         */
        void Draw(const Vec2f& position, const Vec2f& scale, entt::registry& registry, Quadtree<entt::entity>& quadtree, SDL_Renderer* renderer);
    };
}

#endif
