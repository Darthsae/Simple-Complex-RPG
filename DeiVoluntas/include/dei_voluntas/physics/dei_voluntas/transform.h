#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "dei_voluntas/data/vec.h"

using DeiVoluntas::Data::Vec2f;
using DeiVoluntas::Data::Vec3f;

namespace DeiVoluntas::Physics::DeiVoluntas {
    struct Transform2f {
        Vec2f position;
        float rotation;
        Vec2f scale;
    };

    struct Transform3f
    {
        Vec3f position;
        Vec3f rotation;
        Vec3f scale;
    };
}

#endif