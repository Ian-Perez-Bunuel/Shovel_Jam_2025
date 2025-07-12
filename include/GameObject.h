#pragma once

#include "raylib.h"
#include "raymath.h"

#include "../include/Drawable.h"

class GameObject
{
public:
    virtual void init(Vector2 t_pos, float t_radius, Color t_color);

    virtual void draw();
    virtual void update() = 0;

    std::shared_ptr<Drawable> getSprite() const { return sprite; }
    Vector2 getPos() const { return position; }
    float getRadius() const { return radius; }

protected:
    std::shared_ptr<Drawable> sprite;

    bool active = false;

    Vector2 position;
    Vector2 velocity;

    float radius;

    Color color;
};