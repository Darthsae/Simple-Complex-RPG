#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include "ecs_types.h"
#include <memory>
#include <unordered_map>

namespace DeiVoluntas::ECS {
    class SystemManager {
    public:
        template<typename T>
        std::shared_ptr<T> registerSystem();

        template<typename T>
        void setSignature(Signature signature);

        void entityDestroyed(Entity entity);

        void entitySignatureChanged(Entity entity, Signature entitySignature);
    private:
        std::unordered_map<const char*, Signature> signatures;
        std::unordered_map<const char*, std::shared_ptr<System>> systems;
    };
}

#endif