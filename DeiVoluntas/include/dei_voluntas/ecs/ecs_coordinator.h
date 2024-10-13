#ifndef ECS_COORDINATOR_H
#define ECS_COORDINATOR_H

#include "dei_voluntas/ecs/ecs_types.h"
#include "dei_voluntas/ecs/component_manager.h"
#include "dei_voluntas/ecs/entity_manager.h"
#include "dei_voluntas/ecs/system_manager.h"

namespace DeiVoluntas::ECS {
    class Coordinator {
    public:
        void init();

        Entity createEntity();
        void destroyEntity(Entity entity);

        template<typename T>
        void registerComponent();

        template<typename T>
        void addComponent(Entity entity, T component);

        template<typename T>
        void removeComponent(Entity entity);

        template<typename T>
        T& getComponent(Entity entity);

        template<typename T>
        ComponentType getComponentType();

        template<typename T>
        std::shared_ptr<T> registerSystem();

        template<typename T>
        void setSystemSignature(Signature signature);
    private:
        std::unique_ptr<EntityManager> entityManager;
        std::unique_ptr<ComponentManager> componentManager;
        std::unique_ptr<SystemManager> systemManager;
    };
}

#endif