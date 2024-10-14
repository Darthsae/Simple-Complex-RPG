#ifndef RECT_H
#define RECT_H
#include "dei_voluntas/data/vec.h"

namespace DeiVoluntas::Data {
    struct Rect2f {
        float width;
        float height;
    };

    struct Rect2i {
        int width;
        int height;
    };

    struct Rect2d {
        double width;
        double height;
    };

    struct Rect3f {
        float width;
        float height;
        float depth;
    };

    struct Rect3i {
        int width;
        int height;
        int depth;
    };

    struct Rect3d {
        double width;
        double height;
        double depth;
    };
}

#endif