#include "dei_voluntas/physics/transform.h"

using namespace DeiVoluntas::Physics;

#pragma region Transform2f
Transform2f::Transform2f() : position(0, 0), rotation(0), scale(1, 1) {}

Transform2f::Transform2f(Vec2f position, float rotation, Vec2f scale) : position(position), rotation(rotation), scale(scale) {}
#pragma endregion

#pragma region Transform3f
Transform3f::Transform3f() : position(0, 0, 0), rotation(0, 0, 0), scale(1, 1, 1) {}

Transform3f::Transform3f(Vec3f position, Vec3f rotation, Vec3f scale) : position(position), rotation(rotation), scale(scale) {}
#pragma endregion

#pragma region Transform2d
Transform2d::Transform2d() : position(0, 0), rotation(0), scale(1, 1) {}

Transform2d::Transform2d(Vec2d position, double rotation, Vec2d scale) : position(position), rotation(rotation), scale(scale) {}
#pragma endregion

#pragma region Transform3d
Transform3d::Transform3d() : position(0, 0, 0), rotation(0, 0, 0), scale(1, 1, 1) {}

Transform3d::Transform3d(Vec3d position, Vec3d rotation, Vec3d scale) : position(position), rotation(rotation), scale(scale) {}
#pragma endregion