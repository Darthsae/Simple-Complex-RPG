#ifndef SCENE_H
#define SCENE_H
#include <vector>
#include "dei_voluntas/ecs/ecs_types.h"
#include "dei_voluntas/ecs/ecs_coordinator.h"
#include "dei_voluntas/physics/box2d/box2d_physics_system.h"
#include "dei_voluntas/physics/dei_voluntas/dei_voluntas_physics_system.h"
#include "dei_voluntas/graphics/draw_system.h"
#include <SDL.h>

namespace DeiVoluntas {
    enum SceneFlags : uint32_t {
        BOX2D_PHYSICS = 0b00000000000000000000000000000001,
        DEI_VOLUNTAS_PHYSICS = 0b00000000000000000000000000000010,
        SDL2_GRAPHICS = 0b00000000000000000000000000000100
    };

    class Scene {
    public:
        Scene(uint32_t flags);
        virtual ~Scene();

        void Update(float deltaTime);
        void Draw(SDL_Renderer* renderer);

        ECS::Coordinator coordinator;
        std::vector<ECS::Entity> entities;
        Data::Vec2f cameraPosition;
    private:
        std::shared_ptr<Physics::Box2D::Box2DPhysicsSystem> box2dPhysicsSystem;
        std::shared_ptr<Physics::DeiVoluntas::DeiVoluntasPhysicsSystem> deiVoluntasPhysicsSystem;
        std::shared_ptr<Graphics::DrawSystem> drawSystem;
        uint32_t flags;
    };
}

#endif