#include "dei_voluntas/physics/physical_properties.h"

using namespace DeiVoluntas::Physics;

#pragma region PhysicalPropertiesf
PhysicalPropertiesf::PhysicalPropertiesf() : mass(1.0f), angularMass(1.0f) {}

PhysicalPropertiesf::PhysicalPropertiesf(float mass, float angularMass) : mass(mass), angularMass(angularMass) {}
#pragma endregion

#pragma region PhysicalPropertiesd
PhysicalPropertiesd::PhysicalPropertiesd() : mass(1.0), angularMass(1.0) {}

PhysicalPropertiesd::PhysicalPropertiesd(double mass, double angularMass) : mass(mass), angularMass(angularMass) {}
#pragma endregion