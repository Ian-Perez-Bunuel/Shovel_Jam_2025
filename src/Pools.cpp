#include "../include/Pools.h"
#include "../include/Globals.h"

Texture2D ProjectilePool::texture;
std::vector<std::shared_ptr<Projectile>> ProjectilePool::playerProjectiles;
std::vector<std::shared_ptr<Projectile>> ProjectilePool::enemyProjectiles;

std::vector<std::shared_ptr<Pickup>> PickupPool::pickups;
const int PickupPool::PICKUP_POOL_SIZE = 100;

void ProjectilePool::init()
{
    texture = LoadTexture(PLAYER_PATH"/bullet.png");
    // build a real pool of live Projectiles
    playerProjectiles.reserve(PLAYER_POOL_SIZE);
    for (int i = 0; i < PLAYER_POOL_SIZE; ++i)
    {
        playerProjectiles.emplace_back(std::make_shared<Projectile>(texture));
    } 

    enemyProjectiles.reserve(ENEMY_POOL_SIZE);
    for (int i = 0; i < ENEMY_POOL_SIZE; ++i)
    {
        enemyProjectiles.emplace_back(std::make_shared<Projectile>(texture));
    } 
}

void PickupPool::init(float t_radius, std::shared_ptr<Player> t_player)
{
    // build a real pool of live Projectiles
    pickups.reserve(PICKUP_POOL_SIZE);
    for (int i = 0; i < PICKUP_POOL_SIZE; ++i)
    {
        pickups.emplace_back(std::make_shared<Pickup>());
        pickups[i]->init(t_radius, t_player);
    } 
}