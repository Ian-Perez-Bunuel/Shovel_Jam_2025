#pragma once

#include "../include/GameObject.h"
#include "../include/Inventory.h"
#include "../include/Weapon.h"
#include "../include/Health.h"

enum class State
{
    NONE,
    WANDER,
    ATTACK,
    RETREAT
};

class Enemy : public GameObject
{
public:
    void init();

    void draw() override;
    void update(std::shared_ptr<Player>& t_player);
    void checkForPlayer(std::shared_ptr<Player> &t_player);

    Health health;
private:
    Inventory inventory;

    void updateWeaponEffects();
    std::shared_ptr<Weapon> weapon;

    void checkForCollisions();
    float speed = 3;

    State state;
    void checkForPickups();
    // Wandering
    void wander();
    void getNewWanderPos();
    void attack(Vector2 t_target);
    Vector2 wanderPos;
    float wanderRadius = 350;

    static const int PICKUP_RADIUS;

    Vector2 GetRandomPointInCircle(Vector2 center, float radius);
};