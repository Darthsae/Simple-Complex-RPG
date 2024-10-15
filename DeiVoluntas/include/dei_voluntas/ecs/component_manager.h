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
        void registerComponent() {
            const char* typeName = typeid(T).name();

            componentTypes.insert({typeName, nextComponentType});
            componentArrays.insert({typeName, std::make_shared<ComponentArray<T>>()});

            ++nextComponentType;
        }

        template<typename T>
        ComponentType getComponentType(){
            const char* typeName = typeid(T).name();

            return componentTypes[typeName];
        }

        template<typename T>
        void addComponent(Entity entity, T component) {
            getComponentArray<T>()->insertData(entity, component);
        }

        template<typename T>
        void removeComponent(Entity entity) {
            getComponentArray<T>()->removeData(entity);
        }

        template<typename T>
        T& getComponent(Entity entity) {
            return getComponentArray<T>()->getData(entity);
        }

        void entityDestroyed(Entity entity) {
            for (const auto& pair : componentArrays)
            {
                const auto& component = pair.second;

                component->entityDestroyed(entity);
            }
        }
    private:
        std::unordered_map<const char*, ComponentType> componentTypes;
        std::unordered_map<const char*, std::shared_ptr<IComponentArray>> componentArrays;

        ComponentType nextComponentType;

        template<typename T>
        std::shared_ptr<ComponentArray<T>> getComponentArray() {
            const char* typeName = typeid(T).name();

            return std::static_pointer_cast<ComponentArray<T>>(componentArrays[typeName]);
        }
    };
}

#endif