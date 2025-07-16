#pragma once
#include "raylib.h"
#include <vector>
#include "../include/Obstacle.h"

class Projectile;

enum class CollisionSide 
{
    SIDE_NONE = -1,
    SIDE_LEFT = 0,
    SIDE_RIGHT,
    SIDE_TOP,
    SIDE_BOTTOM
};

struct CollisionInfo 
{
    CollisionSide side;
    Vector2 contactPoint;   // point on the rectangle
};

using onHit = void(*)(Projectile* t_projectile, const std::shared_ptr<Obstacle>& t_box, CollisionInfo t_result);
using movement = void(*)(Projectile* t_projectile);

struct Effect
{
    Effect();
    // What changes
    onHit onHitEffect;          // When hitting a wall
    movement movementEffect;    // How the ball moves in the direction given

    int damage = 0;             // How much damage the ball does to other objects
    int shotSpeed = 0;          // Speed of ball
};


class CollisionEffects
{
public:
    static CollisionInfo getCircleRecCollisionSide(Vector2 circlePos, float radius, Rectangle rec);
    // Collision Types
    static void defaultHit(Projectile* t_projectile, const std::shared_ptr<Obstacle>& t_box, CollisionInfo t_result);
};

class MovementEffects
{
public:
    // Movement Types
    static void defaultMovement(Projectile* t_projectile);
};

#include "../include/Projectile.h"