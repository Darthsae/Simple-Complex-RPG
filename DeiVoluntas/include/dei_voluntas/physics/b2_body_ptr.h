/**
 * @file b2_body_ptr.h
 * @brief Defines a smart pointer type for managing Box2D bodies with automatic deletion.
 */

#ifndef B2_BODY_PTR_H
#define B2_BODY_PTR_H
#include <box2d/box2d.h>
#include <memory>

/**
 * @namespace DeiVoluntas::Physics
 * @brief Contains classes and utilities related to physics in the DeiVoluntas engine.
 */
namespace DeiVoluntas::Physics {
    /**
     * @class BodyDeleter
     * @brief Custom deleter for Box2D bodies, ensuring they are properly removed from the Box2D world.
     *
     * The `BodyDeleter` class is used with `std::unique_ptr` to handle the cleanup of Box2D bodies,
     * ensuring they are removed from the world when no longer needed.
     */
    class BodyDeleter {
    public:
        /**
         * @brief Default constructor for BodyDeleter.
         *
         * Initializes `BodyDeleter` without a specific Box2D world.
         */
        BodyDeleter();

        /**
         * @brief Constructs a BodyDeleter with a specific Box2D world.
         *
         * @param world Pointer to the Box2D world containing the body to delete.
         */
        BodyDeleter(b2World *world);

        /**
         * @brief Deletes a Box2D body by removing it from the Box2D world.
         *
         * @param body Pointer to the Box2D body to delete.
         */
        void operator()(b2Body *body);

    private:
        b2World *m_world; ///< Pointer to the Box2D world associated with the body to delete.
    };

    /**
     * @typedef b2BodyPtr
     * @brief A unique pointer type for managing `b2Body` objects with automatic deletion.
     *
     * `b2BodyPtr` is a `std::unique_ptr` configured with the `BodyDeleter` for automatic cleanup of Box2D bodies.
     */
    typedef std::unique_ptr<b2Body, BodyDeleter> b2BodyPtr;
}

#endif
