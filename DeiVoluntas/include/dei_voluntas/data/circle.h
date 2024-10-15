#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "dei_voluntas/data/vec.h"

namespace DeiVoluntas::Data {
    struct Circlef {
        Circlef();
        Circlef(float r);

        float radius;
    };

    struct Circlei {
        Circlei();
        Circlei(int r);

        int radius;
    };

    struct Circled {
        Circled();
        Circled(double r);

        double radius;
    };
}

#endif