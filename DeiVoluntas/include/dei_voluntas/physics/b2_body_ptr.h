#ifndef B2_BODY_PTR_H
#define B2_BODY_PTR_H
#include <box2d/box2d.h>
#include <memory>

namespace DeiVoluntas::Physics {
    class BodyDeleter
    {
    public:
        BodyDeleter();
        BodyDeleter(b2World *world);
        void operator()(b2Body *body);
    private:
        b2World *m_world;
    };

    typedef std::unique_ptr<b2Body, BodyDeleter> b2BodyPtr;
}
#endif