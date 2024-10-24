#ifndef DRAW_SYSTEM_H
#define DRAW_SYSTEM_H
#include "dei_voluntas/data/vec.h"
#include "dei_voluntas/ecs/ecs_coordinator.h"
#include <SDL.h>
#include <vector>
#include "dei_voluntas/data/quadtree.h"
#include <entt/entt.hpp>

using DeiVoluntas::Data::Vec2f;
using DeiVoluntas::Data::Quadtree;

namespace DeiVoluntas::Graphics {
    class DrawSystem : public ECS::System {
    public:
        void Draw(const Vec2f& position, const Vec2f& scale, entt::registry& registry, Quadtree<entt::entity>& quadtree, SDL_Renderer* renderer);
    };
}

#endif