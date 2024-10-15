#include "dei_voluntas/graphics/draw_system.h"
#include "dei_voluntas/graphics/drawable.h"
#include "dei_voluntas/data/circle.h"
#include "dei_voluntas/physics/dei_voluntas/transform.h"
#include "dei_voluntas/physics/dei_voluntas/rigid_body.h"
#include <SDL2_gfxPrimitives.h>

using namespace DeiVoluntas::Graphics;


void DrawSystem::Draw(const Vec2f& position, const std::vector<ECS::Entity>& entities, ECS::Coordinator& coordinator, SDL_Renderer* renderer) {
    for (const auto& entity : entities) {
        auto& circle = coordinator.getComponent<Data::Circlef>(entity);
        auto& transform = coordinator.getComponent<Physics::DeiVoluntas::Transform2f>(entity);
        auto& rigidBody = coordinator.getComponent<Physics::DeiVoluntas::RigidBody2f>(entity);
        auto& drawable = coordinator.getComponent<Drawable>(entity);

        filledCircleRGBA(renderer, (Sint16)(transform.position.x - position.x), (Sint16)(transform.position.y - position.y), (Sint16)(circle.radius * transform.scale.Magnitude()), drawable.color.r, drawable.color.g, drawable.color.b, drawable.color.a);
    }
}