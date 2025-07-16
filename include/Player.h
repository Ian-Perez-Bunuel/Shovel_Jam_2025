#pragma once

#include "../include/GameObject.h"
#include "../include/Inventory.h"
#include "../include/Weapon.h"
#include "../include/Health.h"

class Pickup;

class Player : public GameObject
{
public:
    void init(Vector2 t_pos, float t_radius);

    void draw() override;
    void drawInventory();
    void update();

    std::shared_ptr<Weapon>& getWeapon() { return weapon; }

    void checkForPickups();
    Inventory inventory;
    Health health;

private:
    void input();

    // Weapon
    std::shared_ptr<Weapon> weapon;
    Vector2 weaponPos;
    void updateWeaponEffects();
    void shoot();

    void checkForCollisions();

    // Picking up items
    void pickupClosestItem();
    std::shared_ptr<Pickup> closestItem;

    float speed = 2.0f;


    static const int PICKUP_RADIUS;
};

#include "../include/Pickup.h"