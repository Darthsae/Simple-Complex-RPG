#include "dei_voluntas/ecs/component_manager.h"

using namespace DeiVoluntas::ECS;

template <typename T>
void ComponentManager::registerComponent()
{
    const char* typeName = typeid(T).name();

    componentTypes.insert({typeName, nextComponentType});
    componentArrays.insert({typeName, std::make_shared<ComponentArray<T>>()});

    ++nextComponentType;
}

template <typename T>
ComponentType ComponentManager::getComponentType()
{
    const char* typeName = typeid(T).name();

    return componentTypes[typeName];
}

template <typename T>
void ComponentManager::addComponent(Entity entity, T component)
{
    getComponentArray<T>()->insertData(entity, component);
}

template <typename T>
void ComponentManager::removeComponent(Entity entity)
{
    getComponentArray<T>()->removeData(entity);
}

template <typename T>
T &ComponentManager::getComponent(Entity entity)
{
    return getComponentArray<T>()->getData(entity);
}

void ComponentManager::entityDestroyed(Entity entity)
{
    for (const auto& pair : componentArrays)
    {
        const auto& component = pair.second;

        component->entityDestroyed(entity);
    }
}

template <typename T>
std::shared_ptr<ComponentArray<T>> ComponentManager::getComponentArray()
{
    const char* typeName = typeid(T).name();

    return std::static_pointer_cast<ComponentArray<T>>(componentArrays[typeName]);
}