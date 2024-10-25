#ifndef LINE_H
#define LINE_H
#include "dei_voluntas/data/vec.h"

namespace DeiVoluntas::Data {
    struct Line2f {
        Line2f();
        Line2f(Vec2f pos1, Vec2f pos2);

        Vec2f pos1;
        Vec2f pos2;
    };

    struct Line2i {
        Line2i();
        Line2i(Vec2i pos1, Vec2i pos2);

        Vec2i pos1;
        Vec2i pos2;
    };

    struct Line2d {
        Line2d();
        Line2d(Vec2d pos1, Vec2d pos2);

        Vec2d pos1;
        Vec2d pos2;
    };
}

#endif