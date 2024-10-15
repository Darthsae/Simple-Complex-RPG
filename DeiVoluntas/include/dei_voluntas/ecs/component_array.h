#ifndef COMPONENT_ARRAY_H
#define COMPONENT_ARRAY_H
#include "dei_voluntas/ecs/ecs_types.h"
#include <unordered_map>
#include <array>

namespace DeiVoluntas::ECS {
    class IComponentArray {
    public:
        virtual ~IComponentArray() = default;
        virtual void entityDestroyed(Entity entity) = 0;
    };

    template<typename T>
    class ComponentArray : public IComponentArray {
    public:
        void insertData(Entity entity, T component) {
            size_t newIndex = size;
            entityToIndexMap[entity] = newIndex;
            indexToEntityMap[newIndex] = entity;
            componentArray[newIndex] = component;
            ++size;
        }

        void removeData(Entity entity) {
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

        T& getData(Entity entity) {
            return componentArray[entityToIndexMap[entity]];
        }

        void entityDestroyed(Entity entity) override {
            if (entityToIndexMap.find(entity) != entityToIndexMap.end()) {
                removeData(entity);
            }
        }
    private:
        std::array<T, MAX_ENTITIES> componentArray;

        std::unordered_map<Entity, size_t> entityToIndexMap;
        std::unordered_map<size_t, Entity> indexToEntityMap;

        size_t size;
    };
}

#endif