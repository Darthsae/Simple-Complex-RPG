/**
 * @file scene.h
 * @brief Defines the Scene class, which represents a game scene in the DeiVoluntas engine.
 */

#ifndef SCENE_H
#define SCENE_H
#include <vector>
#include <entt/entt.hpp>
#include "dei_voluntas/physics/physics_system.h"
#include "dei_voluntas/graphics/draw_system.h"
#include "dei_voluntas/graphics/texture.h"
#include "dei_voluntas/data/vec.h"
#include <SDL.h>
#include <box2d/box2d.h>

using DeiVoluntas::Physics::PhysicsSystem;
using DeiVoluntas::Data::Quadtree;
using DeiVoluntas::Data::Vec2f;
using DeiVoluntas::Data::Vec2i;
using DeiVoluntas::Graphics::Texture;

/**
 * @namespace DeiVoluntas
 * @brief Contains classes and utilities for the DeiVoluntas engine.
 */
namespace DeiVoluntas {
    /**
     * @enum SceneFlags
     * @brief Bitwise flags for scene configuration
     *
     * The SceneFlags enum is used to configure the behavior of the scene.
     */
    enum SceneFlags : uint32_t {
        A = 0b00000000000000000000000000000001, ///< Placeholder
    };

    /**
     * @class Scene
     * @brief Represents a game scene containing entities, physics, and rendering systems.
     *
     * The Scene class is responsible for managing the game's state, including the
     * creation and updating of entities, rendering them to the screen, and handling
     * physics simulation.
     */
    class Scene {
    public:
        /**
         * @brief Constructs a new Scene object.
         * 
         * @param flags Bitwise flags for scene configuration.
         * @param cameraPosition Reference to the camera's position in the scene.
         * @param cameraScale Reference to the camera's scale.
         * @param quadtreePosition Position for the quadtree used for spatial partitioning.
         * @param quadtreeSize Size of the quadtree.
         */
        Scene(uint32_t flags, Vec2f& cameraPosition, Vec2f& cameraScale, const Vec2f& quadtreePosition, const Vec2f& quadtreeSize);
        
        /// Destructor for the Scene class.
        virtual ~Scene();

        /**
         * @brief Updates the scene and all entities within it.
         * 
         * This method is called every frame to update the physics simulation and any
         * other necessary game logic.
         * 
         * @param deltaTime Time elapsed since the last update.
         */
        void Update(float deltaTime);

        /**
         * @brief Renders the scene to the provided SDL_Renderer.
         * 
         * This method draws all entities and elements in the scene onto the screen.
         * 
         * @param renderer The SDL_Renderer used for drawing.
         */
        void Draw(SDL_Renderer* renderer);

        #pragma region CreateEntity

        /**
         * @brief Creates a dynamic entity with a circular shape.
         * 
         * @param pos The position of the entity.
         * @param color The color of the entity.
         * @param shape The shape of the entity (b2CircleShape).
         * @param b2BodyType The type of body (dynamic, static, or kinematic).
         * @param density The density of the body, affecting mass.
         * @param friction The friction coefficient for the body.
         * @param restitution The body's bounciness.
         * @param restitutionThreshold The speed threshold for the restitution to take effect.
         * @param vel The initial velocity of the body.
         * @param linearDamping Reduces the linear velocity over time.
         * @param angularVelocity Initial angular velocity for the body.
         * @param angularDamping Reduces the angular velocity over time.
         * @param fixedRotation If true, prevents the body from rotating.
         * @return The newly created entity.
         */
        entt::entity CreateEntity(Vec2f pos, const SDL_Color color, const b2CircleShape& shape, 
                                  b2BodyType b2BodyType = b2_dynamicBody, float density = 1, 
                                  float friction = 0, float restitution = 1, 
                                  float restitutionThreshold = 0, Vec2f vel = Vec2f::ZERO, 
                                  float linearDamping = 0, float angularVelocity = 0, 
                                  float angularDamping = 0, bool fixedRotation = false);

        /**
         * @brief Creates a dynamic entity with an edge shape.
         * 
         * @param pos The position of the entity.
         * @param color The color of the entity.
         * @param shape The shape of the entity (b2EdgeShape).
         * @param b2BodyType The type of body (dynamic, static, or kinematic).
         * @param density The density of the body, affecting mass.
         * @param friction The friction coefficient for the body.
         * @param restitution The body's bounciness.
         * @param restitutionThreshold The speed threshold for the restitution to take effect.
         * @param vel The initial velocity of the body.
         * @param linearDamping Reduces the linear velocity over time.
         * @param angularVelocity Initial angular velocity for the body.
         * @param angularDamping Reduces the angular velocity over time.
         * @param fixedRotation If true, prevents the body from rotating.
         * @return The newly created entity.
         */
        entt::entity CreateEntity(Vec2f pos, const SDL_Color color, const b2EdgeShape& shape, 
                                  b2BodyType b2BodyType = b2_dynamicBody, float density = 1, 
                                  float friction = 0, float restitution = 1, 
                                  float restitutionThreshold = 0, Vec2f vel = Vec2f::ZERO, 
                                  float linearDamping = 0, float angularVelocity = 0, 
                                  float angularDamping = 0, bool fixedRotation = false);

        /**
         * @brief Creates a dynamic entity with a polygon shape.
         * 
         * @param pos The position of the entity.
         * @param color The color of the entity.
         * @param shape The shape of the entity (b2PolygonShape).
         * @param b2BodyType The type of body (dynamic, static, or kinematic).
         * @param density The density of the body, affecting mass.
         * @param friction The friction coefficient for the body.
         * @param restitution The body's bounciness.
         * @param restitutionThreshold The speed threshold for the restitution to take effect.
         * @param vel The initial velocity of the body.
         * @param linearDamping Reduces the linear velocity over time.
         * @param angularVelocity Initial angular velocity for the body.
         * @param angularDamping Reduces the angular velocity over time.
         * @param fixedRotation If true, prevents the body from rotating.
         * @return The newly created entity.
         */
        entt::entity CreateEntity(Vec2f pos, const SDL_Color color, const b2PolygonShape& shape, 
                                  b2BodyType b2BodyType = b2_dynamicBody, float density = 1, 
                                  float friction = 0, float restitution = 1, 
                                  float restitutionThreshold = 0, Vec2f vel = Vec2f::ZERO, 
                                  float linearDamping = 0, float angularVelocity = 0, 
                                  float angularDamping = 0, bool fixedRotation = false);

        #pragma endregion

        /**
         * @brief Adds a texture to the scene.
         * 
         * @param renderer The SDL_Renderer used for rendering.
         * @param assetPath The file path of the texture asset.
         * @param assetName The name to associate with the texture.
         * @return The name of the added texture.
         */
        std::string AddTexture(SDL_Renderer* renderer, const std::string& assetPath, std::string assetName);

        /**
         * @brief Retrieves a texture by name.
         * 
         * @param name The name of the texture to retrieve.
         * @return The requested texture.
         */
        Texture GetTexture(std::string name);

        /**
         * @brief Retrieves a pointer to a texture by name.
         * 
         * @param name The name of the texture to retrieve.
         * @return A pointer to the requested texture.
         */
        Texture* GetTexturePtr(std::string name);

        /**
         * @brief Batch loads multiple textures from a specified asset path.
         * 
         * @param renderer The SDL_Renderer used for rendering.
         * @param assetPath The path to the directory containing texture assets.
         * @return A vector of tuples containing texture names and their respective sizes.
         */
        std::vector<std::tuple<std::string, Vec2i>> BatchLoadTextures(SDL_Renderer* renderer, const std::string& assetPath);

        entt::registry registry; ///< The registry holding all entities and their components.
        Quadtree<entt::entity> quadtree; ///< Spatial partitioning structure for efficient entity management.
        Vec2f cameraPosition; ///< The current position of the camera in the scene.
        Vec2f cameraScale; ///< The current scale of the camera in the scene.

        /**
         * @brief A map of textures, indexed by their names, to allow quick retrieval.
         */
        std::unordered_map<std::string, std::unique_ptr<Texture>> textures;

    private:
        std::unique_ptr<PhysicsSystem> physicsSystem; ///< Pointer to the physics system managing physics interactions.
        std::shared_ptr<Graphics::DrawSystem> drawSystem; ///< Pointer to the draw system for rendering entities.
        uint32_t flags; ///< Flags for scene configuration.
    };
}

#endif