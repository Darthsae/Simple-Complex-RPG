#ifndef DEI_VOLUNTAS_PHYSICS_SYSTEM_H
#define DEI_VOLUNTAS_PHYSICS_SYSTEM_H
#include "dei_voluntas/ecs/ecs_types.h"
#include "dei_voluntas/ecs/ecs_coordinator.h"
#include <vector>

namespace DeiVoluntas::Physics::DeiVoluntas {
    class DeiVoluntasPhysicsSystem : public ECS::System {
    public:
        void Update(const std::vector<ECS::Entity>& entities, ECS::Coordinator& coordinator, float deltaTime);
    };  
}

#endif