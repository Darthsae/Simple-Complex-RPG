/**
 * @file body.h
 * @brief Defines the Body struct, which represents a physical body with a Box2D smart pointer.
 */
#ifndef BODY_H
#define BODY_H
#include "dei_voluntas/physics/b2_body_ptr.h"

/**
 * @namespace DeiVoluntas::Physics
 * @brief Contains physics-related components in the DeiVoluntas engine.
 */
namespace DeiVoluntas::Physics {
    /**
     * @struct Body
     * @brief Represents a physical body with a Box2D smart pointer.
     */
    struct Body {
        b2BodyPtr body; ///< Unique pointer to a Box2D body.
    };
}

#endif
