#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include "ecs_types.h"
#include <memory>
#include <unordered_map>

namespace DeiVoluntas::ECS {
    class SystemManager {
    public:
        template<typename T>
        std::shared_ptr<T> registerSystem() {
            const char* typeName = typeid(T).name();

            auto system = std::make_shared<T>();
            systems.insert({typeName, system});
            return system;
        }

        template<typename T>
        void setSignature(Signature signature) {
            const char* typeName = typeid(T).name();

            signatures.insert({typeName, signature});
        }

        void entityDestroyed(Entity entity) {
            for (const auto& pair : systems) {
                const auto& system = pair.second;

                system->entities.erase(entity);
            }
        }

        void entitySignatureChanged(Entity entity, Signature entitySignature) {
            for (const auto& pair : systems) {
                const auto& type = pair.first;
                const auto& system = pair.second;
                const auto& systemSignature = signatures[type];

                if ((entitySignature & systemSignature) == systemSignature) {
                    system->entities.insert(entity);
                } else {
                    system->entities.erase(entity);
                }
            }
        }
    private:
        std::unordered_map<const char*, Signature> signatures;
        std::unordered_map<const char*, std::shared_ptr<System>> systems;
    };
}

#endif