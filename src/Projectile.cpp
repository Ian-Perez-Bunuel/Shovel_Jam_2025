#include "../include/Projectile.h"
#include "../include/Globals.h"

Projectile::Projectile()
{
    GameObject::init(position, effects.radius, WHITE);
    sprite = std::make_shared<Drawable>(position, active);
    texture = LoadTexture(PLAYER_PATH"/bullet.png");
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

void Projectile::destroy()
{
    active = false;
}

void Projectile::update()
{
    position = Vector2Add(position, velocity);

    if (Vector2Distance(position, spawnPos) > effects.range)
    {
        destroy();
    }
}