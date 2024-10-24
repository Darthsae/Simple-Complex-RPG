#include "dei_voluntas/physics/physics_system.h"
#include "dei_voluntas/physics/transform.h"
#include "dei_voluntas/physics/rigid_body.h"
#include "dei_voluntas/physics/physical_properties.h"
#include "dei_voluntas/physics/body.h"

using namespace DeiVoluntas::Physics;

using DeiVoluntas::Physics::PhysicalPropertiesf;
using DeiVoluntas::Physics::RigidBody2f;
using DeiVoluntas::Physics::Transform2f;
using DeiVoluntas::Physics::Body;

PhysicsSystem::PhysicsSystem(b2Vec2 gravity) : world(gravity) {}

b2BodyPtr PhysicsSystem::CreateBody(float x, float y, const b2Shape& shape, b2BodyType bodyType, float density, float friction, float restitution, float restitutionThreshold, b2Vec2 vel, float linearDamping, float angularVelocity, float angularDamping, bool fixedRotation) {
    b2BodyDef bodyDef;
    bodyDef.type = bodyType;
    bodyDef.position.Set(x, y);
    bodyDef.linearVelocity.Set(vel.x, vel.y);
    bodyDef.linearDamping = linearDamping;
    bodyDef.angularVelocity = angularVelocity;
    bodyDef.angularDamping = angularDamping;
    bodyDef.fixedRotation = fixedRotation;
    b2BodyPtr body(world.CreateBody(&bodyDef), &world);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = density;
    fixtureDef.friction = friction;
    fixtureDef.restitution = restitution;
    fixtureDef.restitutionThreshold = restitutionThreshold;
    body->CreateFixture(&fixtureDef);

    return body;
}

void PhysicsSystem::Update(entt::registry& registry, Quadtree<entt::entity>& quadtree, float deltaTime) {
    world.Step(deltaTime, 8, 3);

    quadtree.Reset();

    auto view = registry.view<Transform2f>();
    for (auto entity : view) {
        auto& pos = view.get<Transform2f>(entity);
        quadtree.Insert({ pos.position.x, pos.position.y, entity });
    }

    auto velocityView = registry.view<Transform2f, RigidBody2f, Body>();
    for (auto entity : velocityView) {
        auto &pos = velocityView.get<Transform2f>(entity);
        auto &vel = velocityView.get<RigidBody2f>(entity);
        auto &body = velocityView.get<Body>(entity);
        b2Vec2 bodyPos = body.body->GetPosition();
        pos.position.x = bodyPos.x;
        pos.position.y = bodyPos.y;
        pos.rotation = body.body->GetAngle();

        b2Vec2 bodyVel = body.body->GetLinearVelocity();
        vel.velocity.x = bodyVel.x;
        vel.velocity.y = bodyVel.y;
        vel.angularVelocity = body.body->GetAngularVelocity();
    }
}

