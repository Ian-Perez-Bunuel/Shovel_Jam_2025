#include "../include/Player.h"
#include <raymath.h>
#include "../include/Globals.h"
#include "../include/Effect.h"

void Player::init(Vector2 t_pos, float t_radius)
{
    GameObject::init(t_pos, t_radius, BLUE);

    inventory.init();

    active = true;
    texture = LoadTexture(PLAYER_PATH"/Player_Atlas.png");
    sprite->setTexture(texture);
    sprite->setAnimations(3, 4, 32, 32);

    // Weapon init
    std::vector<Effect> weaponEffects = inventory.getEffects();
    weapon = std::make_shared<Weapon>(weaponEffects, position);
}

void Player::draw()
{
    GameObject::draw();
}

void Player::drawInventory()
{
    inventory.draw();
}

void Player::update()
{
    input();
    
    velocity = Vector2Scale(velocity, FRICTION);
    position = Vector2Add(position, velocity);

    inventory.update();
}

void Player::checkForPickups(std::vector<std::shared_ptr<Pickup>>& t_pickups)
{
    // Find closest pickup
    float closestDist = 100000000.0f;
    closestItem = nullptr;

    for (std::shared_ptr<Pickup>& item : t_pickups)
    {
        // Check if in range first
        if (Vector2Distance(position, item->getPos()) <= Pickup::PICKUP_RADIUS && item->isActive())
        {
            // In range
            float dist = Vector2Distance(position, item->getPos());
            if (dist < closestDist)
            {
                closestDist = dist;
                closestItem = item;
            }
        }
    }

    // Drop items
    if (IsMouseButtonReleased(1))
    {
        std::shared_ptr<Pickup> droppedItem = inventory.removeItem();
        if (droppedItem != nullptr) // drop if should drop
        {
            t_pickups.push_back(droppedItem);
            updateWeaponEffects();
        }
    }
}

void Player::pickupClosestItem()
{
    if (closestItem != nullptr)
    {
        if (inventory.addItem(closestItem))
        {
            closestItem->pickup();
            closestItem = nullptr;
        }
    }
}

void Player::input()
{
    // Movement
    if (IsKeyDown(KEY_W))
    {
        velocity.y -= speed;
    }
    else if (IsKeyDown(KEY_S))
    {
        velocity.y += speed;
    }  

    if (IsKeyDown(KEY_A))
    {
        velocity.x -= speed;
    }
    else if (IsKeyDown(KEY_D))
    {
        velocity.x += speed;
    } 


    // Toggle inventory on and off
    if (IsKeyReleased(KEY_ESCAPE))
    {
        if (inventory.isShowing())
        {
            inventory.close();
        }
        else
        {
            inventory.open();
        }
    }
    // Pickup item
    if (IsKeyPressed(KEY_E))
    {
        pickupClosestItem();

        updateWeaponEffects();
    }

    // Shooting
    if (IsMouseButtonDown(0))
    {
        shoot();
    }
}

void Player::updateWeaponEffects()
{
    std::vector<Effect> weaponEffects = inventory.getEffects();
    weapon->setWeaponEffects(weaponEffects);
}

void Player::shoot()
{
    weapon->shoot(mousePos);
}