#include "dei_voluntas/ecs/system_manager.h"

using namespace DeiVoluntas::ECS;

template<typename T>
std::shared_ptr<T> SystemManager::registerSystem() {
    const char* typeName = typeid(T).name();

    auto system = std::make_shared<T>();
    systems.insert({typeName, system});
    return system;
}

template <typename T>
void SystemManager::setSignature(Signature signature) {
    const char* typeName = typeid(T).name();

    signatures.insert({typeName, signature});
}

void SystemManager::entityDestroyed(Entity entity) {
    for (const auto& pair : systems) {
        const auto& system = pair.second;

        system->entities.erase(entity);
    }
}

void SystemManager::entitySignatureChanged(Entity entity, Signature entitySignature) {
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