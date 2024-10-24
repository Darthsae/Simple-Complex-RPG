#ifndef PHYSICS_SYSTEM_H
#define PHYSICS_SYSTEM_H
#include <box2d/box2d.h>
#include "dei_voluntas/data/quadtree.h"
#include "dei_voluntas/physics/b2_body_ptr.h"
#include <entt/entt.hpp>

using DeiVoluntas::Data::Quadtree;
using DeiVoluntas::Physics::b2BodyPtr;

namespace DeiVoluntas::Physics {
    class PhysicsSystem {
    public:
        b2World world;

        PhysicsSystem(b2Vec2 gravity = b2Vec2_zero);

        b2BodyPtr CreateBody(float x, float y, const b2Shape& shape, b2BodyType b2BodyType = b2_dynamicBody, float density = 1, float friction = 0, float restitution = 1, float restitutionThreshold = 0, b2Vec2 vel = b2Vec2_zero, float linearDamping = 0, float angularVelocity = 0, float angularDamping = 0, bool fixedRotation = false);

        void Update(entt::registry& registry, Quadtree<entt::entity>& quadtree, float deltaTime);
    };
}
#endif