#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H
#include "dei_voluntas/ecs/ecs_types.h"
#include <queue>
#include <array>

namespace DeiVoluntas::ECS {
    class EntityManager {
    public:
        EntityManager();

        Entity createEntity();

        void destroyEntity(Entity entity);

        void setSignature(Entity entity, Signature signature);

        Signature getSignature(Entity entity);

    private:
        std::queue<Entity> availableEntities;
        std::array<Signature, MAX_ENTITIES> signatures;

        uint32_t livingEntities;
    };
}

#endif