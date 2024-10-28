#include "dei_voluntas/data/line.h"

using namespace DeiVoluntas::Data;

#pragma region Line2f
Line2f::Line2f() {}

Line2f::Line2f(Vec2f pos1, Vec2f pos2) {
    this->pos1 = pos1;
    this->pos2 = pos2;
}
#pragma endregion

#pragma region Line2i
Line2i::Line2i() {}

Line2i::Line2i(Vec2i pos1, Vec2i pos2) {
    this->pos1 = pos1;
    this->pos2 = pos2;
}
#pragma endregion

#pragma region Line2d
Line2d::Line2d() {}

Line2d::Line2d(Vec2d pos1, Vec2d pos2) {
    this->pos1 = pos1;
    this->pos2 = pos2;
}
#pragma endregion