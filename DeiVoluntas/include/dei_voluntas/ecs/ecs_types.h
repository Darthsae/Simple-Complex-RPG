#ifndef ECS_TYPES_H
#define ECS_TYPES_H
#include <cstdint>
#include <bitset>
#include <set>

namespace DeiVoluntas::ECS {
    using Entity = std::uint32_t;
    const Entity MAX_ENTITIES = 5000;

    using ComponentType = std::uint8_t;
    const ComponentType MAX_COMPONENTS = 32;

    using Signature = std::bitset<MAX_COMPONENTS>;

    class System {
    public:
        std::set<Entity> entities;
    };
}

#endif