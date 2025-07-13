#include "../include/Projectile.h"

Projectile::Projectile()
{
    active = false;
}

void Projectile::shoot(Effect &t_effects, Vector2 t_pos, Vector2 t_dir)
{
    effects = t_effects; 
    position = t_pos;
    velocity = Vector2Scale(Vector2Normalize(t_dir), effects.shotSpeed);

    GameObject::init(position, effects.radius, WHITE);

    sprite = std::make_shared<Drawable>(position, active);
    sprite->setTexture(effects.texture);

    active = true;
}

void Projectile::update()
{
    position = Vector2Add(position, velocity);
}