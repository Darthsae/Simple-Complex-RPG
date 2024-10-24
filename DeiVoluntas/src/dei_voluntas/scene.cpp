#include "dei_voluntas/scene.h"
#include "dei_voluntas/physics/physical_properties.h"
#include "dei_voluntas/physics/rigid_body.h"
#include "dei_voluntas/physics/transform.h"
#include "dei_voluntas/graphics/drawable.h"
#include "dei_voluntas/physics/body.h"

using namespace DeiVoluntas;

using DeiVoluntas::Physics::PhysicalPropertiesf;
using DeiVoluntas::Physics::RigidBody2f;
using DeiVoluntas::Physics::Transform2f;
using DeiVoluntas::Graphics::Drawable;
using DeiVoluntas::Data::Vec2f;
using DeiVoluntas::Data::Body;

Scene::Scene(uint32_t flags, Vec2f& cameraPosition, Vec2f& cameraScale, const Vec2f& quadtreePosition, const Vec2f& quadtreeSize): 
    flags(flags),
    cameraPosition(cameraPosition),
    cameraScale(cameraScale),
    registry(),
    quadtree(quadtreePosition.x, quadtreePosition.y, quadtreeSize.x, quadtreeSize.y, 10)
{
    physicsSystem = std::make_unique<PhysicsSystem>();
    drawSystem = std::make_unique<Graphics::DrawSystem>();
}

Scene::~Scene()
{
}

void Scene::Update(float deltaTime) {
    physicsSystem->Update(registry, quadtree, deltaTime);
}

void Scene::Draw(SDL_Renderer* renderer) {
    drawSystem->Draw(cameraPosition, cameraScale, registry, quadtree, renderer);
}
entt::entity Scene::CreateEntity(Vec2f pos, const SDL_Color color, const b2CircleShape &shape, b2BodyType b2BodyType, float density, float friction, float restitution, float restitutionThreshold, b2Vec2 vel, float linearDamping, float angularVelocity, float angularDamping, bool fixedRotation)
{
    const auto entity = registry.create();
    float x = pos.x;
    float y = pos.y;
    float density = density;
    float radius = shape.m_radius;
    registry.emplace<Transform2f>(entity, pos, 0.0f);
    registry.emplace<RigidBody2f>(entity, vel, angularVelocity);
    registry.emplace<Body>(entity, physicsSystem->CreateBody(x, y, shape, b2BodyType, density, friction, restitution, restitutionThreshold, vel, linearDamping, angularVelocity, angularDamping, fixedRotation));
    registry.emplace<Drawable>(entity, color);
}