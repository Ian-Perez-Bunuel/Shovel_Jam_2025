#include "../include/Pickup.h"
#include "../include/Globals.h"

const float Pickup::TRACKING_RADIUS = 100.0f;

void Pickup::init(float t_radius, std::shared_ptr<Player> t_player)
{
    player = t_player;

    GameObject::init({100, 100}, 10, YELLOW);
}

void Pickup::spawn(Vector2 t_pos)
{
    position = t_pos;
    active = true;
}

void Pickup::draw()
{
    if (active)
    {
        GameObject::draw();
    }
}

void Pickup::update()
{
    if (Vector2Distance(player->getPos(), position) <= TRACKING_RADIUS)
    {
        Vector2 dir = Vector2Normalize(Vector2Subtract(player->getPos(), position));    
        dir = Vector2Scale(dir, 5.0f);

        velocity = dir;
    }
    else
    {
        velocity = Vector2Scale(velocity, FRICTION);
    }

    position = Vector2Add(position, velocity);
}