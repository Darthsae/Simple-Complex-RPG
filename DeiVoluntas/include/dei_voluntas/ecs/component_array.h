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
        void insertData(Entity entity, T component);
        void removeData(Entity entity);

        T& getData(Entity entity);
        void entityDestroyed(Entity entity) override;

    private:
        std::array<T, MAX_ENTITIES> componentArray;

        std::unordered_map<Entity, size_t> entityToIndexMap;
        std::unordered_map<size_t, Entity> indexToEntityMap;

        size_t size;
    };
}

#endif