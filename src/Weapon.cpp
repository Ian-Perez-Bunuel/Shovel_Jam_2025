#include "../include/Weapon.h"
#include "../include/Globals.h"

Weapon::Weapon(std::vector<Effect>& t_effects, Vector2& t_holderPos)
    :    position(t_holderPos)
{
    // Set original staff stats
    ORIGINAL_STATS.onHitEffects.push_back(defaultEffect);
    ORIGINAL_STATS.damage = ORIGINAL_DMG;
    ORIGINAL_STATS.range = ORIGINAL_RANGE;
    ORIGINAL_STATS.shotSpeed = ORIGINAL_SHOTSPEED;
    ORIGINAL_STATS.radius = ORIGINAL_RADIUS;
    ORIGINAL_STATS.firerate = ORIGINAL_FIRERATE;
    setWeaponEffects(t_effects);

    texture = LoadTexture(PLAYER_PATH "/weapon.png");
    sprite  = std::make_shared<Drawable>(position, active);
    sprite->setTexture(texture);

    // build a real pool of live Projectiles
    projectiles.reserve(PROJECTILE_POOL_SIZE);
    for (int i = 0; i < PROJECTILE_POOL_SIZE; ++i)
    {
        projectiles.emplace_back(std::make_shared<Projectile>());
    } 
}

void Weapon::setWeaponEffects(std::vector<Effect>& t_effects)
{
    for (Effect& effect : t_effects)
    {
        // Add all effects to the staff's effect
        for (onHit& hitEffect : effect.onHitEffects)
        {
            itemEffects.onHitEffects.push_back(hitEffect);
        }

        itemEffects.damage += effect.damage;
        itemEffects.firerate += effect.firerate;
        itemEffects.range += effect.range;
        itemEffects.shotSpeed += effect.shotSpeed;
        itemEffects.radius += effect.radius;
    }

    // Give the stats/effects to the staff
    for (onHit& hitEffect : itemEffects.onHitEffects)
    {
        staffStats.onHitEffects.push_back(hitEffect);
    }

    staffStats.damage = itemEffects.damage + ORIGINAL_STATS.damage;
    staffStats.firerate = itemEffects.firerate + ORIGINAL_STATS.firerate;
    staffStats.range = itemEffects.range + ORIGINAL_STATS.range;
    staffStats.shotSpeed = itemEffects.shotSpeed + ORIGINAL_STATS.shotSpeed;
    staffStats.radius = itemEffects.radius + ORIGINAL_STATS.radius;
}


void Weapon::shoot(Vector2 t_target)
{
    Vector2 dir = Vector2Subtract(t_target, position);

    for (std::shared_ptr<Projectile>& proj : projectiles)
    {
        if (!proj->isActive())
        {
            proj->shoot(staffStats, position, dir);
            break;
        }
    }
}

void Weapon::updateProjectiles()
{
    for (std::shared_ptr<Projectile>& proj : projectiles)
    {
        if (proj->isActive())
        {
            proj->update();
        }
    }
}