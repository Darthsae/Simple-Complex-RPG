#ifndef RIGID_BODY_H
#define RIGID_BODY_H
#include "dei_voluntas/data/vec.h"

using DeiVoluntas::Data::Vec2f;
using DeiVoluntas::Data::Vec3f;

namespace DeiVoluntas::Physics::DeiVoluntas {
    struct RigidBody2f {
        Vec2f velocity;
        float angularVelocity;
    };

    struct RigidBody3f {
        Vec3f velocity;
        Vec3f angularVelocity;
    };
}

#endif