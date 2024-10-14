#include "dei_voluntas/physics/dei_voluntas/dei_voluntas_physics_system.h"
#include "dei_voluntas/physics/dei_voluntas/physical_properties.h"
#include "dei_voluntas/physics/dei_voluntas/rigid_body.h"
#include "dei_voluntas/physics/dei_voluntas/transform.h"

using namespace DeiVoluntas::Physics::DeiVoluntas;

void DeiVoluntasPhysicsSystem::Update(const std::vector<ECS::Entity>& entities, ECS::Coordinator& coordinator, float deltaTime) {
    for (const auto& entity : entities) {
        auto& properties = coordinator.getComponent<PhysicalPropertiesf>(entity);
        auto& rigidBody = coordinator.getComponent<RigidBody2f>(entity);
        auto& transform = coordinator.getComponent<Transform2f>(entity);

        transform.position += rigidBody.velocity * deltaTime;
        transform.rotation += rigidBody.angularVelocity * deltaTime;
    }
}