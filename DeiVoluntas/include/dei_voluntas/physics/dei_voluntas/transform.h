#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "dei_voluntas/data/vec.h"

using DeiVoluntas::Data::Vec2f;
using DeiVoluntas::Data::Vec3f;
using DeiVoluntas::Data::Vec2d;
using DeiVoluntas::Data::Vec3d;

namespace DeiVoluntas::Physics::DeiVoluntas {
    struct Transform2f {
        Transform2f();
        Transform2f(Vec2f position, float rotation, Vec2f scale);

        Vec2f position;
        float rotation;
        Vec2f scale;
    };

    struct Transform3f {
        Transform3f();
        Transform3f(Vec3f position, Vec3f rotation, Vec3f scale);

        Vec3f position;
        Vec3f rotation;
        Vec3f scale;
    };

    struct Transform2d {
        Transform2d();
        Transform2d(Vec2d position, double rotation, Vec2d scale);

        Vec2d position;
        double rotation;
        Vec2d scale;
    };

    struct Transform3d {
        Transform3d();
        Transform3d(Vec3d position, Vec3d rotation, Vec3d scale);

        Vec3d position;
        Vec3d rotation;
        Vec3d scale;
    };
}

#endif