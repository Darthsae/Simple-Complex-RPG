#include "dei_voluntas/ecs/ecs_coordinator.h"

using namespace DeiVoluntas::ECS;

void Coordinator::init() {
    entityManager = std::make_unique<EntityManager>();
    componentManager = std::make_unique<ComponentManager>();
    systemManager = std::make_unique<SystemManager>();
}

Entity DeiVoluntas::ECS::Coordinator::createEntity() {
    return entityManager->createEntity();
}

void DeiVoluntas::ECS::Coordinator::destroyEntity(Entity entity) {
    entityManager->destroyEntity(entity);
    componentManager->entityDestroyed(entity);
    systemManager->entityDestroyed(entity);
}

template<typename T>
void Coordinator::registerComponent() {
    componentManager->registerComponent<T>();
}

template <typename T>
void Coordinator::addComponent(Entity entity, T component) {
    componentManager->addComponent<T>(entity, component);

    auto signature = entityManager->getSignature(entity);
    signature.set(componentManager->getComponentType<T>(), true);
    entityManager->setSignature(entity, signature);

    systemManager->entitySignatureChanged(entity, signature);
}

template <typename T>
void Coordinator::removeComponent(Entity entity) {
    componentManager->removeComponent<T>(entity);

    auto signature = entityManager->getSignature(entity);
    signature.set(componentManager->getComponentType<T>(), false);
    entityManager->setSignature(entity, signature);

    systemManager->entitySignatureChanged(entity, signature);
}

template <typename T>
T &Coordinator::getComponent(Entity entity) {
    return componentManager->getComponent<T>(entity);
}

template <typename T>
ComponentType Coordinator::getComponentType() {
    return componentManager->getComponentType<T>();
}

template <typename T>
std::shared_ptr<T> Coordinator::registerSystem() {
    return systemManager->registerSystem<T>();
}

template <typename T>
void Coordinator::setSystemSignature(Signature signature) {
    systemManager->setSignature<T>(signature);
}
