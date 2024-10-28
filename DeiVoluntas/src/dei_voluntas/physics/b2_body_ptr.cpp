#include "dei_voluntas/physics/b2_body_ptr.h"

using namespace DeiVoluntas::Physics;

BodyDeleter::BodyDeleter() : m_world(NULL) {}

BodyDeleter::BodyDeleter(b2World *world) : m_world(world) {}

void BodyDeleter::operator()(b2Body *body) {
    if (m_world) m_world->DestroyBody(body);
}