/**
 * @file rigid_body.h
 * @brief Defines rigid body components for different dimensionalities and data types.
 */

#ifndef RIGID_BODY_H
#define RIGID_BODY_H
#include "dei_voluntas/data/vec.h"

using DeiVoluntas::Data::Vec2f;
using DeiVoluntas::Data::Vec3f;
using DeiVoluntas::Data::Vec2d;
using DeiVoluntas::Data::Vec3d;

/**
 * @namespace DeiVoluntas::Physics
 * @brief Defines rigid body components for different dimensionalities and data types.
 */
namespace DeiVoluntas::Physics {

    /**
     * @struct RigidBody2f
     * @brief Represents a 2D rigid body using single-precision floats.
     *
     * Contains the linear and angular velocity of a 2D rigid body.
     */
    struct RigidBody2f {
        /**
         * @brief Default constructor initializing velocity and angular velocity to zero.
         */
        RigidBody2f();

        /**
         * @brief Constructs a 2D rigid body with specified velocity and angular velocity.
         * @param velocity Linear velocity of the rigid body.
         * @param angularVelocity Angular velocity of the rigid body.
         */
        RigidBody2f(Vec2f velocity, float angularVelocity);

        Vec2f velocity; ///< Linear velocity of the rigid body.
        float angularVelocity; ///< Angular velocity of the rigid body.
    };

    /**
     * @struct RigidBody3f
     * @brief Represents a 3D rigid body using single-precision floats.
     *
     * Contains the linear and angular velocity of a 3D rigid body.
     */
    struct RigidBody3f {
        /**
         * @brief Default constructor initializing velocity and angular velocity to zero.
         */
        RigidBody3f();

        /**
         * @brief Constructs a 3D rigid body with specified velocity and angular velocity.
         * @param velocity Linear velocity of the rigid body.
         * @param angularVelocity Angular velocity of the rigid body.
         */
        RigidBody3f(Vec3f velocity, Vec3f angularVelocity);

        Vec3f velocity; ///< Linear velocity of the rigid body.
        Vec3f angularVelocity; ///< Angular velocity of the rigid body.
    };

    /**
     * @struct RigidBody2d
     * @brief Represents a 2D rigid body using double-precision floats.
     *
     * Contains the linear and angular velocity of a 2D rigid body.
     */
    struct RigidBody2d {
        /**
         * @brief Default constructor initializing velocity and angular velocity to zero.
         */
        RigidBody2d();

        /**
         * @brief Constructs a 2D rigid body with specified velocity and angular velocity.
         * @param velocity Linear velocity of the rigid body.
         * @param angularVelocity Angular velocity of the rigid body.
         */
        RigidBody2d(Vec2d velocity, double angularVelocity);

        Vec2d velocity; ///< Linear velocity of the rigid body.
        double angularVelocity; ///< Angular velocity of the rigid body.
    };

    /**
     * @struct RigidBody3d
     * @brief Represents a 3D rigid body using double-precision floats.
     *
     * Contains the linear and angular velocity of a 3D rigid body.
     */
    struct RigidBody3d {
        /**
         * @brief Default constructor initializing velocity and angular velocity to zero.
         */
        RigidBody3d();

        /**
         * @brief Constructs a 3D rigid body with specified velocity and angular velocity.
         * @param velocity Linear velocity of the rigid body.
         * @param angularVelocity Angular velocity of the rigid body.
         */
        RigidBody3d(Vec3d velocity, Vec3d angularVelocity);

        Vec3d velocity; ///< Linear velocity of the rigid body.
        Vec3d angularVelocity; ///< Angular velocity of the rigid body.
    };
}

#endif
