#include "../include/Pickup.h"
#include "../include/Globals.h"

const float Pickup::PICKUP_RADIUS = 250.0f;

void Pickup::init(float t_radius, std::shared_ptr<Player> t_player)
{
    player = t_player;

    GameObject::init({100, 100}, 10, YELLOW);

    texture = LoadTexture(PICKUPS_PATH"/stick.png");
    sprite->setTexture(texture);
}

void Pickup::spawn(Vector2 t_pos)
{
    position = t_pos;
    active = true;
}

void Pickup::update()
{
    if (checkCollision() && IsKeyPressed(KEY_E))
    {
        onPickup();
    }
}

void Pickup::draw()
{
    if (active)
    {
        DrawCircleV(position, PICKUP_RADIUS, GREEN);
        GameObject::draw();
    }
}

bool Pickup::checkCollision()
{
    if (CheckCollisionCircles(position, PICKUP_RADIUS, player->getPos(), player->getRadius()))
    {
        return true;
    }
    return false;
}

void Pickup::onPickup()
{
    player->inventory.addItem(shared_from_this());
    active = false;
    inInventory = true;
}