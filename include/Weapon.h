#pragma once

#include "raylib.h"
#include "stdio.h"
#include <memory>

#include "../include/Effect.h"

class Drawable;
class Projectile;

class Weapon
{
public:
    Weapon(std::vector<Effect>& t_effects, Vector2& t_holderPos);

    void shoot(Vector2 t_target);
    std::shared_ptr<Drawable>& getSprite() { return sprite; }

    void draw();
    void updateProjectiles();
private:

    void setWeaponEffects(std::vector<Effect>& t_effects);
    Effect weaponEffects;
    std::vector<std::shared_ptr<Projectile>> projectiles;
    static const int PROJECTILE_POOL_SIZE = 100;

    Texture2D texture;
    std::shared_ptr<Drawable> sprite;
    bool active = true;
    Vector2& position;
};

#include "../include/Projectile.h"
#include "../include/Drawable.h"