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

    void update() override;

private:

    Effect effects;
};
