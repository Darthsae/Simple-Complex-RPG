#ifndef SCENE_H
#define SCENE_H
#include <vector>
#include <entt/entt.hpp>
#include "dei_voluntas/physics/physics_system.h"
#include "dei_voluntas/graphics/draw_system.h"
#include "dei_voluntas/graphics/texture.h"
#include "dei_voluntas/data/vec.h"
#include <SDL.h>
#include <box2d/box2d.h>

using DeiVoluntas::Physics::PhysicsSystem;
using DeiVoluntas::Data::Quadtree;
using DeiVoluntas::Data::Vec2f;
using DeiVoluntas::Data::Vec2i;
using DeiVoluntas::Graphics::Texture;

namespace DeiVoluntas {
    enum SceneFlags : uint32_t {
        A = 0b00000000000000000000000000000001,
    };

    class Scene {
    public:
        Scene(uint32_t flags, Vec2f& cameraPosition, Vec2f& cameraScale, const Vec2f& quadtreePosition, const Vec2f& quadtreeSize);
        virtual ~Scene();

        void Update(float deltaTime);
        void Draw(SDL_Renderer* renderer);

        #pragma region CreateEntity
        entt::entity CreateEntity(Vec2f pos, const SDL_Color color, const b2CircleShape &shape, b2BodyType b2BodyType = b2_dynamicBody, float density = 1, float friction = 0, float restitution = 1, float restitutionThreshold = 0, Vec2f vel = Vec2f::ZERO, float linearDamping = 0, float angularVelocity = 0, float angularDamping = 0, bool fixedRotation = false);
        entt::entity CreateEntity(Vec2f pos, const SDL_Color color, const b2EdgeShape &shape, b2BodyType b2BodyType = b2_dynamicBody, float density = 1, float friction = 0, float restitution = 1, float restitutionThreshold = 0, Vec2f vel = Vec2f::ZERO, float linearDamping = 0, float angularVelocity = 0, float angularDamping = 0, bool fixedRotation = false);
        entt::entity CreateEntity(Vec2f pos, const SDL_Color color, const b2PolygonShape &shape, b2BodyType b2BodyType = b2_dynamicBody, float density = 1, float friction = 0, float restitution = 1, float restitutionThreshold = 0, Vec2f vel = Vec2f::ZERO, float linearDamping = 0, float angularVelocity = 0, float angularDamping = 0, bool fixedRotation = false);
        #pragma endregion

        std::string AddTexture(SDL_Renderer* renderer, const std::string& assetPath, std::string assetName);
        Texture GetTexture(std::string name);
        Texture* GetTexturePtr(std::string name);

        std::vector<std::tuple<std::string, Vec2i>> BatchLoadTextures(SDL_Renderer* renderer, const std::string& assetPath);

        entt::registry registry;
        Quadtree<entt::entity> quadtree;
        Vec2f cameraPosition;
        Vec2f cameraScale;
        std::unordered_map<std::string, std::unique_ptr<Texture>> textures;
    private:
        std::unique_ptr<PhysicsSystem> physicsSystem;
        std::shared_ptr<Graphics::DrawSystem> drawSystem;
        uint32_t flags;
    };
}

#endif