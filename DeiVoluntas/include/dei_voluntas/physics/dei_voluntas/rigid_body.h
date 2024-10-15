#ifndef RIGID_BODY_H
#define RIGID_BODY_H
#include "dei_voluntas/data/vec.h"

using DeiVoluntas::Data::Vec2f;
using DeiVoluntas::Data::Vec3f;

using DeiVoluntas::Data::Vec2d;
using DeiVoluntas::Data::Vec3d;

namespace DeiVoluntas::Physics::DeiVoluntas {
    struct RigidBody2f {
        RigidBody2f();
        RigidBody2f(Vec2f velocity, float angularVelocity);

        Vec2f velocity;
        float angularVelocity;
    };

    struct RigidBody3f {
        RigidBody3f();
        RigidBody3f(Vec3f velocity, Vec3f angularVelocity);

        Vec3f velocity;
        Vec3f angularVelocity;
    };

    struct RigidBody2d {
        RigidBody2d();
        RigidBody2d(Vec2d velocity, double angularVelocity);

        Vec2d velocity;
        double angularVelocity;
    };

    struct RigidBody3d {
        RigidBody3d();
        RigidBody3d(Vec3d velocity, Vec3d angularVelocity);

        Vec3d velocity;
        Vec3d angularVelocity;
    };
}

#endif