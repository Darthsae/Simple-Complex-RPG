#include "dei_voluntas/ecs/entity_manager.h"

using namespace DeiVoluntas::ECS;

EntityManager::EntityManager() {
    for (Entity i = 0; i < MAX_ENTITIES; i++) {
        availableEntities.push(i);
    }
}

Entity EntityManager::createEntity() {
    Entity id = availableEntities.front();
    availableEntities.pop();
    livingEntities++;

    return id;
}

void EntityManager::destroyEntity(Entity entity) {
    signatures[entity].reset();
    availableEntities.push(entity);
    livingEntities--;
}

void EntityManager::setSignature(Entity entity, Signature signature) {
    signatures[entity] = signature;
}

Signature EntityManager::getSignature(Entity entity) {
    return signatures[entity];
}