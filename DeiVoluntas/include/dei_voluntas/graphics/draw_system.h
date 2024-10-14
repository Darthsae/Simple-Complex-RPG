#ifndef DRAW_SYSTEM_H
#define DRAW_SYSTEM_H
#include "dei_voluntas/data/vec.h"
#include "dei_voluntas/ecs/ecs_coordinator.h"
#include <SDL.h>
#include <vector>

namespace DeiVoluntas::Graphics {
    class DrawSystem : public ECS::System {
    public:
        void Draw(const Data::Vec2f& position, const std::vector<ECS::Entity>& entities, ECS::Coordinator& coordinator, SDL_Renderer* renderer);
    };
}

#endif