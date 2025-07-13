#pragma once

#include "../include/GameObject.h"
#include "../include/Inventory.h"
#include "../include/Weapon.h"

class Pickup;

class Player : public GameObject
{
public:
    void init(Vector2 t_pos, float t_radius);

    void draw() override;
    void drawInventory();
    void update();

    Weapon& getWeapon() { return *weapon; }

    void checkForPickups(std::vector<std::shared_ptr<Pickup>>& t_pickups);
    Inventory inventory;

private:
    void input();

    // Weapon
    std::shared_ptr<Weapon> weapon;
    Vector2 weaponPos;
    void updateWeaponEffects();
    void shoot();

    // Picking up items
    void pickupClosestItem();
    std::shared_ptr<Pickup> closestItem;

    float speed = 2.0f;
};

#include "../include/Pickup.h"