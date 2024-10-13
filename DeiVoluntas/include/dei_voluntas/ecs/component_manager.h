#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include "dei_voluntas/ecs/ecs_types.h"
#include "dei_voluntas/ecs/component_array.h"
#include <unordered_map>
#include <memory>

namespace DeiVoluntas::ECS {
    class ComponentManager {
    public:
        template<typename T>
        void registerComponent();

        template<typename T>
        ComponentType getComponentType();

        template<typename T>
        void addComponent(Entity entity, T component);

        template<typename T>
        void removeComponent(Entity entity);

        template<typename T>
        T& getComponent(Entity entity);

        void entityDestroyed(Entity entity);
    private:
        std::unordered_map<const char*, ComponentType> componentTypes;
        std::unordered_map<const char*, std::shared_ptr<IComponentArray>> componentArrays;

        ComponentType nextComponentType;

        template<typename T>
        std::shared_ptr<ComponentArray<T>> getComponentArray();
    };
}

#endif