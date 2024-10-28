/**
 * @file physical_properties.h
 * @brief Defines physical properties of objects, like mass and angular mass.
 */

#ifndef PHYSICAL_PROPERTIES_H
#define PHYSICAL_PROPERTIES_H

/**
 * @namespace DeiVoluntas::Physics
 * @brief Defines physical properties of objects, like mass and angular mass.
 */
namespace DeiVoluntas::Physics {

    /**
     * @struct PhysicalPropertiesf
     * @brief Physical properties using single-precision floating point values.
     *
     * Represents physical attributes, such as mass and angular mass, for objects
     * where single-precision floating-point values are sufficient.
     */
    struct PhysicalPropertiesf {
        /**
         * @brief Default constructor initializes mass and angular mass to zero.
         */
        PhysicalPropertiesf();

        /**
         * @brief Constructs PhysicalPropertiesf with specified mass and angular mass.
         * @param mass The mass of the object.
         * @param angularMass The angular mass of the object.
         */
        PhysicalPropertiesf(float mass, float angularMass);

        float mass; ///< Mass of the object.
        float angularMass; ///< Angular mass of the object.
    };

    /**
     * @struct PhysicalPropertiesd
     * @brief Physical properties using double-precision floating point values.
     *
     * Represents physical attributes, such as mass and angular mass, for objects
     * requiring double-precision floating-point values for greater accuracy.
     */
    struct PhysicalPropertiesd {
        /**
         * @brief Default constructor initializes mass and angular mass to zero.
         */
        PhysicalPropertiesd();

        /**
         * @brief Constructs PhysicalPropertiesd with specified mass and angular mass.
         * @param mass The mass of the object.
         * @param angularMass The angular mass of the object.
         */
        PhysicalPropertiesd(double mass, double angularMass);

        double mass; ///< Mass of the object.
        double angularMass; ///< Angular mass of the object.
    };
}

#endif
