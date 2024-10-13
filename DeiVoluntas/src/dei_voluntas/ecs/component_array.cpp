#include "dei_voluntas/ecs/component_array.h"

using namespace DeiVoluntas::ECS;

template<typename T>
void ComponentArray<T>::insertData(Entity entity, T component) {
    size_t newIndex = size;
    entityToIndexMap[entity] = newIndex;
    indexToEntityMap[newIndex] = entity;
    componentArray[newIndex] = component;
    ++size;
}

template <typename T>
void ComponentArray<T>::removeData(Entity entity)
{
    size_t indexOfRemovedEntity = entityToIndexMap[entity];
    size_t indexOfLastElement = size - 1;
    componentArray[indexOfRemovedEntity] = componentArray[indexOfLastElement];

    Entity entityOfLastElement = indexToEntityMap[indexOfLastElement];
    entityToIndexMap[entityOfLastElement] = indexOfRemovedEntity;
    indexToEntityMap[indexOfRemovedEntity] = entityOfLastElement;

    entityToIndexMap.erase(entity);
    indexToEntityMap.erase(indexOfLastElement);

    --size;
}

template <typename T>
T &ComponentArray<T>::getData(Entity entity)
{
    return componentArray[entityToIndexMap[entity]];
}

template <typename T>
void ComponentArray<T>::entityDestroyed(Entity entity)
{
    if (entityToIndexMap.find(entity) != entityToIndexMap.end()) {
        removeData(entity);
    }
}