#pragma once

#include "raylib.h"
#include "raymath.h"

#include "../include/Drawable.h"

class GameObject
{
public:
    virtual void init(Vector2 t_pos, Color t_color);

    virtual void draw() = 0;
    virtual void update() {}

    std::shared_ptr<Drawable> getSprite() const { return sprite; }
    Vector2 getPos() const { return position; }

    bool isActive() { return active; }

protected:
    std::shared_ptr<Drawable> sprite;

    bool active = false;

    Vector2 position;

    Color color = GRAY;
};