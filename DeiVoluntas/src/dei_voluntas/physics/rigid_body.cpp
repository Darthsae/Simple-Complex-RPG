#include "dei_voluntas/physics/rigid_body.h"

using namespace DeiVoluntas::Physics;

#pragma region RigidBody2f
RigidBody2f::RigidBody2f() : velocity(0.0f, 0.0f), angularVelocity(0.0f) {}

RigidBody2f::RigidBody2f(Vec2f velocity, float angularVelocity) : velocity(velocity), angularVelocity(angularVelocity) {}
#pragma endregion

#pragma region RigidBody3f
RigidBody3f::RigidBody3f() : velocity(0.0f, 0.0f, 0.0f), angularVelocity(0.0f, 0.0f, 0.0f) {}

RigidBody3f::RigidBody3f(Vec3f velocity, Vec3f angularVelocity) : velocity(velocity), angularVelocity(angularVelocity) {}
#pragma endregion

#pragma region RigidBody2d
RigidBody2d::RigidBody2d() : velocity(0.0, 0.0), angularVelocity(0.0) {}

RigidBody2d::RigidBody2d(Vec2d velocity, double angularVelocity) : velocity(velocity), angularVelocity(angularVelocity) {}
#pragma endregion

#pragma region RigidBody3d
RigidBody3d::RigidBody3d() : velocity(0.0, 0.0, 0.0), angularVelocity(0.0, 0.0, 0.0) {}

RigidBody3d::RigidBody3d(Vec3d velocity, Vec3d angularVelocity) : velocity(velocity), angularVelocity(angularVelocity) {}
#pragma endregion