#include "dei_voluntas/scene.h"
#include "dei_voluntas/physics/dei_voluntas/physical_properties.h"
#include "dei_voluntas/physics/dei_voluntas/rigid_body.h"
#include "dei_voluntas/physics/dei_voluntas/transform.h"
#include "dei_voluntas/graphics/drawable.h"

using namespace DeiVoluntas;

Scene::Scene(uint32_t flags) {
    coordinator = ECS::Coordinator();
    coordinator.init();
    
    /*if ((flags >> 0) & 1 == 1) {
        coordinator.registerComponent<b2Body>();
        box2dPhysicsSystem = coordinator.registerSystem<Physics::Box2D::Box2DPhysicsSystem>();
        
        ECS::Signature physicsSignature;
        physicsSignature.set(coordinator.getComponentType<b2Body>(), true);
        coordinator.setSystemSignature<Physics::Box2D::Box2DPhysicsSystem>(physicsSignature);
    }*/

    coordinator.registerComponent<Physics::DeiVoluntas::PhysicalPropertiesf>();
    coordinator.registerComponent<Physics::DeiVoluntas::RigidBody2f>();
    coordinator.registerComponent<Physics::DeiVoluntas::Transform2f>();
    deiVoluntasPhysicsSystem = coordinator.registerSystem<Physics::DeiVoluntas::DeiVoluntasPhysicsSystem>();
    
    ECS::Signature physicsSignature;
    physicsSignature.set(coordinator.getComponentType<Physics::DeiVoluntas::PhysicalPropertiesf>(), true);
    physicsSignature.set(coordinator.getComponentType<Physics::DeiVoluntas::RigidBody2f>(), true);
    physicsSignature.set(coordinator.getComponentType<Physics::DeiVoluntas::Transform2f>(), true);
    coordinator.setSystemSignature<Physics::DeiVoluntas::DeiVoluntasPhysicsSystem>(physicsSignature);

    cameraPosition = Data::Vec2f(0.0f, 0.0f);

    coordinator.registerComponent<Data::Circlef>();
    coordinator.registerComponent<Graphics::Drawable>();
    drawSystem = coordinator.registerSystem<Graphics::DrawSystem>();

    ECS::Signature drawingSignature;
    drawingSignature.set(coordinator.getComponentType<Data::Circlef>(), true);
    drawingSignature.set(coordinator.getComponentType<Graphics::Drawable>(), true);
    coordinator.setSystemSignature<Graphics::DrawSystem>(drawingSignature);

    entities.reserve(ECS::MAX_ENTITIES);

    for (ECS::Entity i = 0; i < ECS::MAX_ENTITIES; i++) {
        entities.push_back(coordinator.createEntity());
    }
}

Scene::~Scene()
{
    box2dPhysicsSystem.~shared_ptr();
    deiVoluntasPhysicsSystem.~shared_ptr();
    drawSystem.~shared_ptr();
    entities.clear();
}

void Scene::Update(float deltaTime) {
    /*if ((flags >> 0) & 1) {
        box2dPhysicsSystem->Update(entities, coordinator, deltaTime);
    }*/

    deiVoluntasPhysicsSystem->Update(entities, coordinator, deltaTime);
}

void Scene::Draw(SDL_Renderer* renderer) {
    drawSystem->Draw(cameraPosition, entities, coordinator, renderer);
}