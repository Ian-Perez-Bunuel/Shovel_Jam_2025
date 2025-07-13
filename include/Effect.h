#pragma once
#include "raylib.h"
#include <vector>


using onHit = void(*)();

struct Effect
{
    Effect();
    // What changes

    // Projectile
    Texture2D texture;
    std::vector<onHit> onHitEffects;
    int damage = 1;
    int range = 100;
    int shotSpeed = 10;
    int radius = 10;

    // Weapon
    int firerate = 2;

};