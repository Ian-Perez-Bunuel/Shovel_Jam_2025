#include "../include/Projectile.h"
#include "../include/Globals.h"

Projectile::Projectile(Texture2D& t_texture)
    : texture(t_texture)
{
    GameObject::init(position, effects.radius, WHITE);
    sprite = std::make_shared<Drawable>(position, active);
    sprite->setTexture(texture);
    active = false;
}

void Projectile::shoot(Effect &t_effects, Vector2 t_pos, Vector2 t_dir)
{
    effects = t_effects; 
    position = t_pos;
    spawnPos = position;
    radius = effects.radius;
    velocity = Vector2Scale(Vector2Normalize(t_dir), effects.shotSpeed);

    active = true;
}

void Projectile::hit()
{
    for (onHit effect : effects.onHitEffects)
    {
        effect();
    }
    active = false;
}

void Projectile::update()
{
    position = Vector2Add(position, velocity);

    if (Vector2Distance(position, spawnPos) > effects.range)
    {
        hit();
    }
}

void Projectile::draw()
{
    if (active)
    {
        GameObject::draw();
    }
}