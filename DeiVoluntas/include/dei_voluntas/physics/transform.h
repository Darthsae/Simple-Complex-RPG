/**
 * @file transform.h
 * @brief Defines transform components for positioning and scaling entities.
 */

#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "dei_voluntas/data/vec.h"

using DeiVoluntas::Data::Vec2f;
using DeiVoluntas::Data::Vec3f;
using DeiVoluntas::Data::Vec2d;
using DeiVoluntas::Data::Vec3d;

/**
 * @namespace DeiVoluntas::Physics
 * @brief Defines transform components for positioning and scaling entities.
 */
namespace DeiVoluntas::Physics {

    /**
     * @struct Transform2f
     * @brief Represents a 2D transform with position, rotation, and scale.
     *
     * The Transform2f structure encapsulates a 2D position vector, rotation angle, and scale vector,
     * used to define an entity's spatial configuration in a 2D environment.
     */
    struct Transform2f {
        /**
         * @brief Default constructor initializing to the origin, no rotation, and unit scale.
         */
        Transform2f();

        /**
         * @brief Constructs a Transform2f with specified position, rotation, and scale.
         * @param position Position of the entity in 2D space.
         * @param rotation Rotation angle in radians.
         * @param scale Scale vector in 2D space.
         */
        Transform2f(Vec2f position, float rotation, Vec2f scale);

        Vec2f position; ///< Position of the entity in 2D space.
        float rotation; ///< Rotation angle of the entity.
        Vec2f scale; ///< Scale of the entity in 2D space.
    };

    /**
     * @struct Transform3f
     * @brief Represents a 3D transform with position, rotation, and scale.
     *
     * The Transform3f structure encapsulates a 3D position vector, a 3D rotation vector, and a scale vector,
     * used to define an entity's spatial configuration in a 3D environment.
     */
    struct Transform3f {
        /**
         * @brief Default constructor initializing to the origin, no rotation, and unit scale.
         */
        Transform3f();

        /**
         * @brief Constructs a Transform3f with specified position, rotation, and scale.
         * @param position Position of the entity in 3D space.
         * @param rotation Rotation of the entity around each axis.
         * @param scale Scale vector in 3D space.
         */
        Transform3f(Vec3f position, Vec3f rotation, Vec3f scale);

        Vec3f position; ///< Position of the entity in 3D space.
        Vec3f rotation; ///< Rotation of the entity around each axis.
        Vec3f scale; ///< Scale of the entity in 3D space.
    };

    /**
     * @struct Transform2d
     * @brief Represents a 2D transform with position, rotation, and scale using double precision.
     *
     * The Transform2d structure provides a 2D position vector, rotation angle, and scale vector
     * with double precision, intended for high-accuracy spatial configurations in a 2D environment.
     */
    struct Transform2d {
        /**
         * @brief Default constructor initializing to the origin, no rotation, and unit scale.
         */
        Transform2d();

        /**
         * @brief Constructs a Transform2d with specified position, rotation, and scale.
         * @param position Position of the entity in 2D space.
         * @param rotation Rotation angle in radians.
         * @param scale Scale vector in 2D space.
         */
        Transform2d(Vec2d position, double rotation, Vec2d scale);

        Vec2d position; ///< Position of the entity in 2D space.
        double rotation; ///< Rotation angle of the entity.
        Vec2d scale; ///< Scale of the entity in 2D space.
    };

    /**
     * @struct Transform3d
     * @brief Represents a 3D transform with position, rotation, and scale using double precision.
     *
     * The Transform3d structure encapsulates a 3D position vector, rotation vector, and scale vector 
     * with double precision, useful for high-accuracy spatial configurations in a 3D environment.
     */
    struct Transform3d {
        /**
         * @brief Default constructor initializing to the origin, no rotation, and unit scale.
         */
        Transform3d();

        /**
         * @brief Constructs a Transform3d with specified position, rotation, and scale.
         * @param position Position of the entity in 3D space.
         * @param rotation Rotation of the entity around each axis.
         * @param scale Scale vector in 3D space.
         */
        Transform3d(Vec3d position, Vec3d rotation, Vec3d scale);

        Vec3d position; ///< Position of the entity in 3D space.
        Vec3d rotation; ///< Rotation of the entity around each axis.
        Vec3d scale; ///< Scale of the entity in 3D space.
    };

}

#endif
