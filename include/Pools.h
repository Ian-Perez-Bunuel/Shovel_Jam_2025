#pragma once

#include <vector>
#include <memory>
#include "../include/Projectile.h"
#include "../include/Pickup.h"

class ProjectilePool
{
public:
    static void init();
    static std::vector<std::shared_ptr<Projectile>> playerProjectiles;
    // Shared between all enemies
    static std::vector<std::shared_ptr<Projectile>> enemyProjectiles;

private: 
    static const int PLAYER_POOL_SIZE = 100;
    static const int ENEMY_POOL_SIZE = 500;

    static Texture2D texture;
};

class PickupPool
{
public:
    static void init(float t_radius, std::shared_ptr<Player> t_player);
    static std::vector<std::shared_ptr<Pickup>> pickups;

    static const int PICKUP_POOL_SIZE;
private: 
};