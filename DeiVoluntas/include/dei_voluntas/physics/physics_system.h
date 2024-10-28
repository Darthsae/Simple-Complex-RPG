/**
 * @file physics_system.h
 * @brief Contains the PhysicsSystem class for managing physics in the DeiVoluntas engine.
 */

#ifndef PHYSICS_SYSTEM_H
#define PHYSICS_SYSTEM_H
#include <box2d/box2d.h>
#include "dei_voluntas/data/quadtree.h"
#include "dei_voluntas/physics/b2_body_ptr.h"
#include <entt/entt.hpp>

using DeiVoluntas::Data::Quadtree;
using DeiVoluntas::Physics::b2BodyPtr;

/**
 * @namespace DeiVoluntas::Physics
 * @brief Contains classes and systems for managing physics in the DeiVoluntas engine.
 */
namespace DeiVoluntas::Physics {

    /**
     * @class PhysicsSystem
     * @brief Manages the physics world and updates physics entities in the DeiVoluntas engine.
     *
     * The PhysicsSystem class encapsulates a Box2D physics world and provides methods to 
     * create bodies and update entity physics states based on world conditions and interactions.
     */
    class PhysicsSystem {
    public:
        b2World world; ///< Box2D world for physics simulation.

        /**
         * @brief Constructs a new PhysicsSystem with a specified gravity vector.
         * @param gravity The gravity vector applied to all bodies in the physics world.
         */
        PhysicsSystem(b2Vec2 gravity = b2Vec2_zero);

        /**
         * @brief Creates a new body in the physics world.
         * 
         * This method allows customization of various body parameters such as shape, density,
         * friction, and damping. The body can also be fixed from rotation or set to an initial velocity.
         * 
         * @param x X-coordinate of the body.
         * @param y Y-coordinate of the body.
         * @param shape The shape of the body.
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
         * @return A pointer to the created body in the physics world.
         */
        b2BodyPtr CreateBody(float x, float y, const b2Shape& shape, b2BodyType b2BodyType = b2_dynamicBody,
                             float density = 1, float friction = 0, float restitution = 1, 
                             float restitutionThreshold = 0, b2Vec2 vel = b2Vec2_zero, 
                             float linearDamping = 0, float angularVelocity = 0, 
                             float angularDamping = 0, bool fixedRotation = false);

        /**
         * @brief Updates the physics system and entities within the registry.
         *
         * This method advances the physics simulation by a time step and updates 
         * each relevant entity's state in the provided registry. The quadtree can be 
         * utilized for spatial partitioning of entities.
         *
         * @param registry The registry holding all entities and components.
         * @param quadtree Spatial partitioning structure for optimizing collision checks.
         * @param deltaTime Time step for advancing the physics simulation.
         */
        void Update(entt::registry& registry, Quadtree<entt::entity>& quadtree, float deltaTime);
    };
}

#endif
