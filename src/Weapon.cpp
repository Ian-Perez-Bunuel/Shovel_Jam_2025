#include "../include/Weapon.h"
#include "../include/Pools.h"
#include "../include/Globals.h"

Weapon::Weapon(std::vector<Effect>& t_effects, Vector2& t_holderPos, std::vector<std::shared_ptr<Projectile>>& t_projectilePool)
    :    position(t_holderPos), projectiles(t_projectilePool)
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
}

void Weapon::setWeaponEffects(std::vector<Effect>& t_effects)
{
    itemEffects.onHitEffects.clear();
    staffStats.onHitEffects.clear();

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

void Weapon::shootCounter()
{
    // Check if can shoot
    if (firerateTimer < staffStats.firerate)
    {
        firerateTimer += GetFrameTime();
    }
    else
    {
        firerateTimer = 0;

        canShoot = true;
    }
}


void Weapon::shoot(Vector2 t_target)
{
    if (canShoot)
    {
        Vector2 dir = Vector2Subtract(t_target, position);

        for (std::shared_ptr<Projectile>& proj : projectiles)
        {
            if (!proj->isActive())
            {
                proj->shoot(staffStats, position, dir);
                canShoot = false;
                break;
            }
        }
    }
}

void Weapon::updateProjectiles()
{
    if (!canShoot)
    {
        shootCounter();
    }

    for (std::shared_ptr<Projectile>& proj : projectiles)
    {
        if (proj->isActive())
        {
            proj->update();
        }
    }
}