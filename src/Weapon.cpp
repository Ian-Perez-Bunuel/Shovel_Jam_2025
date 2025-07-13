#include "../include/Weapon.h"
#include "../include/Globals.h"

Weapon::Weapon(std::vector<Effect>& t_effects, Vector2& t_holderPos)
    :    position(t_holderPos)
{
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
            weaponEffects.onHitEffects.push_back(hitEffect);
        }

        weaponEffects.texture = effect.texture; // How the projectile looks

        weaponEffects.damage += effect.damage;
        weaponEffects.firerate += effect.firerate;
        weaponEffects.range += effect.range;
        weaponEffects.shotSpeed += effect.shotSpeed;
        weaponEffects.radius += effect.radius;
    }
}


void Weapon::shoot(Vector2 t_target)
{
    Vector2 dir = Vector2Subtract(position, t_target);

    for (std::shared_ptr<Projectile>& proj : projectiles)
    {
        if (!proj->isActive())
        {
            proj->shoot(weaponEffects, position, dir);
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
            break;
        }
    }
}