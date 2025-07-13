#pragma once

#include "raylib.h"
#include "stdio.h"

#include "../include/Pickup.h"
#include "../include/Effect.h"


class Projectile : public GameObject
{
public:
    Projectile();

    void shoot(Effect& t_effects, Vector2 t_pos, Vector2 t_dir);
    void destroy();

    void update() override;

private:
    Vector2 spawnPos;

    Effect effects;
    Texture2D texture;
};
