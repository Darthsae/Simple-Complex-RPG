#ifndef BOX2D_PHYSICS_SYSTEM_H
#define BOX2D_PHYSICS_SYSTEM_H
#include <Box2D/Box2D.h>
#include "dei_voluntas/ecs/ecs_types.h"
#include "dei_voluntas/ecs/ecs_coordinator.h"
#include <vector>

namespace DeiVoluntas::Physics::Box2D {
    class Box2DPhysicsSystem : public ECS::System {
    public:
        void Update(const std::vector<ECS::Entity>& entities, ECS::Coordinator& coordinator, float deltaTime);
    };
}

#endif