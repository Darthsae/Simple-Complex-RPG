#ifndef BODY_H
#define BODY_H
#include "dei_voluntas/physics/b2_body_ptr.h"

namespace DeiVoluntas::Physics {
    struct Body {
        b2BodyPtr body;
    };
}
#endif