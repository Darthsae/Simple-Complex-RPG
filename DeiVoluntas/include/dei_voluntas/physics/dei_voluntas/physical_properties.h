#ifndef PHYSICAL_PROPERTIES_H
#define PHYSICAL_PROPERTIES_H

namespace DeiVoluntas::Physics::DeiVoluntas {
    struct PhysicalPropertiesf {
        PhysicalPropertiesf();
        PhysicalPropertiesf(float mass, float angularMass);

        float mass;
        float angularMass;
    };

    struct PhysicalPropertiesd {
        PhysicalPropertiesd();
        PhysicalPropertiesd(double mass, double angularMass);

        double mass;
        double angularMass;
    };
}

#endif