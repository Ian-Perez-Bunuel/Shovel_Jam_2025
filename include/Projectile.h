#pragma once

#include "raylib.h"
#include "stdio.h"

#include "../include/Pickup.h"
#include "../include/Effect.h"


class Projectile : public GameObject
{
public:
    Projectile(Texture2D& t_texture);

    void shoot(Effect& t_effects, Vector2 t_pos, Vector2 t_dir);
    void hit();

    void update() override;
    void draw() override;

    int getDamage() { return effects.damage; }

private:
    Vector2 spawnPos;

    Effect effects;
    Texture2D& texture;
};
