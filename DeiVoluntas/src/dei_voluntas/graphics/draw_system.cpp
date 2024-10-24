#include "dei_voluntas/graphics/draw_system.h"
#include "dei_voluntas/graphics/drawable.h"
#include "dei_voluntas/data/circle.h"
#include "dei_voluntas/physics/transform.h"
#include "dei_voluntas/physics/rigid_body.h"
#include <SDL2_gfxPrimitives.h>

using namespace DeiVoluntas::Graphics;


void DrawSystem::Draw(const Vec2f& position, const Vec2f& scale, entt::registry& registry, Quadtree<entt::entity>& quadtree, SDL_Renderer* renderer) {
    auto drawableView = registry.view<Data::Circlef, Physics::Transform2f, Physics::RigidBody2f, Drawable>();
    for (auto entity : drawableView) {
        auto& circle = drawableView.get<Data::Circlef>(entity);
        auto& transform = drawableView.get<Physics::Transform2f>(entity);
        auto& rigidBody = drawableView.get<Physics::RigidBody2f>(entity);
        auto& drawable = drawableView.get<Drawable>(entity);

        filledCircleRGBA(renderer, (Sint16)(transform.position.x - position.x), (Sint16)(transform.position.y - position.y), (Sint16)(circle.radius * transform.scale.Magnitude()), drawable.color.r, drawable.color.g, drawable.color.b, drawable.color.a);
    }
}