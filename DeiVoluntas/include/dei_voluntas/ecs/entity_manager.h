#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H
#include "dei_voluntas/ecs/ecs_types.h"
#include <queue>
#include <array>

namespace DeiVoluntas::ECS {
    class EntityManager {
    public:
        EntityManager() {
            for (Entity i = 0; i < MAX_ENTITIES; i++) {
                availableEntities.push(i);
            }
        }

        Entity createEntity() {
            Entity id = availableEntities.front();
            availableEntities.pop();
            livingEntities++;

            return id;
        }

        void destroyEntity(Entity entity) {
            signatures[entity].reset();
            availableEntities.push(entity);
            livingEntities--;
        }

        void setSignature(Entity entity, Signature signature) {
            signatures[entity] = signature;
        }

        Signature getSignature(Entity entity) {
            return signatures[entity];
        }
    private:
        std::queue<Entity> availableEntities;
        std::array<Signature, MAX_ENTITIES> signatures;

        uint32_t livingEntities;
    };
}

#endif