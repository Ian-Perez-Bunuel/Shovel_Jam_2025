#pragma once

#include "raylib.h"
#include "stdio.h"

#include "../include/Projectile.h"

class Goal
{
public:
    void init(Vector2 t_pos);

    void draw();
    bool checkForBall(std::shared_ptr<Projectile>& t_ball);

    Vector2 getPos() { return position; }

private:
    Vector2 position;
    float radius = 22.5f;
};