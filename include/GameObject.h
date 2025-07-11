#pragma once

#include "raylib.h"
#include "raymath.h"

class GameObject
{
public:
    virtual void init(Vector2 t_pos, float t_radius, Color t_color);

    virtual void draw();
    virtual void update() = 0;

    Vector2 getPos() const { return position; }

protected:
    Vector2 position;
    Vector2 velocity;

    float radius;

    Color color;
};