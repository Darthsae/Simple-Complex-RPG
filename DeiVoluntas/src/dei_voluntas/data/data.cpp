#include "dei_voluntas/data/circle.h"

using namespace DeiVoluntas::Data;

#pragma region Circlef
Circlef::Circlef() : radius(0.0f) {}
Circlef::Circlef(float r) : radius(r) {}
#pragma endregion

#pragma region Circlei
Circlei::Circlei() : radius(0) {}
Circlei::Circlei(int r) : radius(r) {}
#pragma endregion

#pragma region Circled
Circled::Circled() : radius(0.0) {}
Circled::Circled(double r) : radius(r) {}
#pragma endregion