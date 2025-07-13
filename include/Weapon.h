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
    std::vector<std::shared_ptr<Projectile>>& getProjectiles() { return projectiles; }

    void draw();
    void updateProjectiles();

    void setWeaponEffects(std::vector<Effect>& t_effects);
private:

    Effect ORIGINAL_STATS;
    const int ORIGINAL_DMG = 1;
    const int ORIGINAL_RANGE = 350;
    const int ORIGINAL_SHOTSPEED = 10;
    const int ORIGINAL_RADIUS = 10;
    const int ORIGINAL_FIRERATE = 1;

    Effect staffStats;
    Effect itemEffects;
    std::vector<std::shared_ptr<Projectile>> projectiles;
    static const int PROJECTILE_POOL_SIZE = 100;

    Texture2D texture;
    std::shared_ptr<Drawable> sprite;
    bool active = true;
    Vector2& position;
};

#include "../include/Projectile.h"
#include "../include/Drawable.h"