#include "dei_voluntas/graphics/draw_system.h"
#include "dei_voluntas/graphics/drawable.h"
#include "dei_voluntas/graphics/sprite.h"
#include "dei_voluntas/data/circle.h"
#include "dei_voluntas/data/line.h"
#include "dei_voluntas/physics/transform.h"
#include "dei_voluntas/physics/rigid_body.h"
#include "dei_voluntas/physics/body.h"
#include <SDL2_gfxPrimitives.h>
#include <iostream>

using namespace DeiVoluntas::Graphics;

using DeiVoluntas::Data::QuadtreeNode;


void DrawSystem::Draw(const Vec2f& position, const Vec2f& scale, entt::registry& registry, Quadtree<entt::entity>& quadtree, SDL_Renderer* renderer) {
    auto drawableCircleView = registry.view<Data::Circlef, Physics::Transform2f, Drawable>();
    auto drawableLineView = registry.view<Data::Line2f, Physics::Transform2f, Drawable>();
    auto drawableTextureView = registry.view<Sprite, Physics::Transform2f, Drawable>();

    /*
    for (auto entity : drawableCircleView) {
        auto& circle = drawableCircleView.get<Data::Circlef>(entity);
        auto& transform = drawableCircleView.get<Physics::Transform2f>(entity);
        auto& rigidBody = drawableCircleView.get<Physics::RigidBody2f>(entity);
        auto& drawable = drawableCircleView.get<Drawable>(entity);

        filledCircleRGBA(renderer, (Sint16)(quadtree.x - (transform.position.x - position.x)), (Sint16)(quadtree.y - (transform.position.y - position.y)), (Sint16)(circle.radius), drawable.color.r, drawable.color.g, drawable.color.b, drawable.color.a);
    }*/

    std::vector<QuadtreeNode<entt::entity>> found;
    quadtree.Query(position.x - scale.x * 0.5f, position.y - scale.y * 0.5f, scale.x * 0.75f, found);

    ///*
    for (auto entity : found) {
        if (drawableCircleView.contains(entity.value)) {
            auto& circle = drawableCircleView.get<Data::Circlef>(entity.value);
            auto& transform = drawableCircleView.get<Physics::Transform2f>(entity.value);
            auto& drawable = drawableCircleView.get<Drawable>(entity.value);

            filledCircleRGBA(renderer, (Sint16)(quadtree.x - (transform.position.x - position.x)), (Sint16)(quadtree.y - (transform.position.y - position.y)), (Sint16)(circle.radius), drawable.color.r, drawable.color.g, drawable.color.b, drawable.color.a);
        }
        else if (drawableTextureView.contains(entity.value)) {
            auto& sprite = drawableTextureView.get<Sprite>(entity.value);
            auto& transform = drawableCircleView.get<Physics::Transform2f>(entity.value);
            auto& drawable = drawableCircleView.get<Drawable>(entity.value);
            auto& body = registry.get<Physics::Body>(entity.value);

            SDL_Rect rect = SDL_Rect({(Sint16)(quadtree.x - (transform.position.x - position.x) - sprite.texture->size.x * 0.5f), (Sint16)(quadtree.y - (transform.position.y - position.y) - sprite.texture->size.y * 0.5f), sprite.texture->size.x, sprite.texture->size.y});

            if (SDL_RenderCopyEx(renderer, sprite.texture->texture, NULL, &rect, transform.rotation * 180 / M_PI, NULL, SDL_RendererFlip::SDL_FLIP_NONE) != 0) {
                std::cout << "Error: " << SDL_GetError() << std::endl;
            }
        }
        

        //if (transform.position.x > position.x + circle.radius || transform.position.x + scale.x < position.x - circle.radius || transform.position.y > position.y + circle.radius || transform.position.y + scale.y < position.y - circle.radius) {
        //    continue;
        //}

        
    }//*/

    for (auto entity : drawableLineView) {
        auto& line = drawableLineView.get<Data::Line2f>(entity);
        auto& transform = drawableLineView.get<Physics::Transform2f>(entity);
        auto& drawable = drawableLineView.get<Drawable>(entity);

        Vec2f positionOfRotation = Vec2f((transform.position.x - position.x), (transform.position.y - position.y));

        Vec2f point1 = Vec2f((positionOfRotation.x + (line.pos1.x)), (positionOfRotation.y + (line.pos1.y)));
        Vec2f point2 = Vec2f((positionOfRotation.x + (line.pos2.x)), (positionOfRotation.y + (line.pos2.y)));

        /*
        if (!((point2.x < transform.position.x && point1.x < transform.position.x) || (point2.x > transform.position.x + scale.x && point1.x > transform.position.x + scale.x) || (point2.y < transform.position.y && point1.y < transform.position.y) || (point2.y > transform.position.y + scale.y && point1.y > transform.position.y + scale.y))) {
            thickLineRGBA(renderer, (Sint16)(quadtree.x - point1.x), (Sint16)(quadtree.y - point1.y), (Sint16)(quadtree.x - point2.x), (Sint16)(quadtree.y - point2.y), 1, drawable.color.r, drawable.color.g, drawable.color.b, drawable.color.a);
        }*/

        thickLineRGBA(renderer, (Sint16)(quadtree.x - point1.x), (Sint16)(quadtree.y - point1.y), (Sint16)(quadtree.x - point2.x), (Sint16)(quadtree.y - point2.y), 1, drawable.color.r, drawable.color.g, drawable.color.b, drawable.color.a);
    }
}