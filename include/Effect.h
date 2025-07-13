#pragma once
#include "raylib.h"
#include <vector>


using onHit = void(*)();

struct Effect
{
    Effect();
    // What changes

    // Projectile
    std::vector<onHit> onHitEffects;
    int damage = 0;
    int range = 0;
    int shotSpeed = 0;
    int radius = 0;
    // Weapon
    int firerate = 0;

};

void defaultEffect();