#include "../include/Enemy.h"
#include "../include/Pools.h"
#include "../include/Globals.h"

const int Enemy::PICKUP_RADIUS = 50;

void Enemy::init()
{
    GameObject::init({0, 0}, 25, RED);
    texture = LoadTexture(ENEMY_PATH"/goblin.png");
    sprite->setTexture(texture);

    inventory.init();
    health.init(100);

    // Weapon init
    std::vector<Effect> weaponEffects = inventory.getEffects();
    weapon = std::make_shared<Weapon>(weaponEffects, position, ProjectilePool::enemyProjectiles);

    // texture = LoadTexture(ENEMY_PATH"goblin.png");
    active = true;
    state = State::WANDER;
}

void Enemy::draw()
{
    if (active)
    {
        DrawCircleV(position, weapon->getStats().range, YELLOW);
        DrawCircleV(position, PICKUP_RADIUS, WHITE);
        GameObject::draw();

        health.draw({position.x, position.y - (sprite->getTexture().height +25)});
        inventory.draw();
    }
}

void Enemy::update(std::shared_ptr<Player> &t_player)
{
    checkForCollisions();
    checkForPlayer(t_player);

    switch (state)
    {
    case State::NONE:
        break;

    case State::WANDER:
        wander();
        break;

    case State::ATTACK:
        attack(t_player->getPos());
        break;

    case State::RETREAT:
        break;
    }

    weapon->updateProjectiles();
}

void Enemy::checkForPlayer(std::shared_ptr<Player> &t_player)
{
    if (CheckCollisionCircles(position, weapon->getStats().range, t_player->getPos(), t_player->getRadius()))
    {
        state = State::ATTACK;
    }
    else
    {
        state = State::WANDER;
    }
}

void Enemy::checkForCollisions()
{
    for (std::shared_ptr<Projectile>& proj : ProjectilePool::playerProjectiles)
    {
        if (proj->isActive())
        {
            if (CheckCollisionCircles(proj->getPos(), proj->getRadius(), position, radius))
            {
                health.takeDamage(proj->getDamage());
                proj->hit();
            }
        }
    }
}

void Enemy::checkForPickups()
{
    // Find closest pickup
    float closestDist = 100000000.0f;
    std::shared_ptr<Pickup> closestItem = nullptr;

    for (std::shared_ptr<Pickup>& item : PickupPool::pickups)
    {
        if (item->isActive() && item != nullptr)
        {
                    // Check if in range first
            if (Vector2Distance(position, item->getPos()) <= PICKUP_RADIUS && item->isActive())
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
    }

    if (closestItem != nullptr)
    {
        if (inventory.addItem(closestItem))
        {
            closestItem->pickup();
            closestItem = nullptr;
        }
        updateWeaponEffects();
    }
}

void Enemy::updateWeaponEffects()
{
    std::vector<Effect> weaponEffects = inventory.getEffects();
    weapon->setWeaponEffects(weaponEffects);
}

void Enemy::wander()
{   
    // Change target pos
    if (Vector2Distance(position, wanderPos) <= 5) // Reached the position wanted
    {
        getNewWanderPos();
    }
    else
    {
        checkForPickups();
        position += velocity;
    }
}

void Enemy::getNewWanderPos()
{
    wanderPos = GetRandomPointInCircle(position, wanderRadius);
    Vector2 dir = Vector2Subtract(wanderPos, position);
    velocity = Vector2Scale(Vector2Normalize(dir), speed);
}

void Enemy::attack(Vector2 t_target)
{
    weapon->shoot(t_target);
}

// Returns a random point inside the circle of given center & radius
Vector2 Enemy::GetRandomPointInCircle(Vector2 center, float radius)
{
    // 1. Random “area weight” in [0,1)
    float u = (float)rand()/(float)RAND_MAX;

    // 2. Radius scaled by sqrt of u
    float r = radius * sqrtf(u);

    // 3. Uniform angle in [0, 2π)
    float theta = ((float)rand()/(float)RAND_MAX)*(2*PI);

    // 4. Convert polar → Cartesian
    Vector2 p;
    p.x = center.x + r*cosf(theta);
    p.y = center.y + r*sinf(theta);
    return p;
}