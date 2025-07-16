#include "../include/Effect.h"
#include "../include/Globals.h"
#include "stdio.h"

CollisionInfo CollisionEffects::getCircleRecCollisionSide(Vector2 circlePos, float radius, Rectangle rec)
{
    CollisionInfo result{ CollisionSide::SIDE_NONE, {0,0} };

    // 1) Quick reject
    if (!CheckCollisionCircleRec(circlePos, radius, rec)) 
        return result;

    // 2) Find the closest point on the rect to the circle center
    Vector2 closest = {
        Clamp(circlePos.x, rec.x,       rec.x + rec.width),
        Clamp(circlePos.y, rec.y,       rec.y + rec.height)
    };

    // 3) Vector from that point to the circle center
    Vector2 diff = Vector2Subtract(circlePos, closest);

    // 4) Decide which axis dominates
    if (fabs(diff.x) > fabs(diff.y)) {
        result.side = (diff.x > 0) ? CollisionSide::SIDE_RIGHT : CollisionSide::SIDE_LEFT;
    }
    else {
        result.side = (diff.y > 0) ? CollisionSide::SIDE_BOTTOM : CollisionSide::SIDE_TOP;
    }

    // 5) Store the contact point *on the rectangle*
    result.contactPoint = closest;

    return result;
}

void CollisionEffects::defaultHit(Projectile* t_projectile, const std::shared_ptr<Obstacle>& t_box, CollisionInfo t_result)
{
    switch(t_result.side)
    {
        case CollisionSide::SIDE_LEFT:   // hit the left side of the box
            t_projectile->velocity.x *= -1;
            break;
        case CollisionSide::SIDE_RIGHT:
            t_projectile->velocity.x *= -1;
            break;
        case CollisionSide::SIDE_TOP:
            t_projectile->velocity.y *= -1;
            break;
        case CollisionSide::SIDE_BOTTOM:
            t_projectile->velocity.y *= -1;
            break;
        default:
            // no collision
            break;
    }
}

void MovementEffects::defaultMovement(Projectile* t_projectile)
{
    t_projectile->position = Vector2Add(t_projectile->position, t_projectile->velocity);
    t_projectile->velocity = Vector2Scale(t_projectile->velocity, FRICTION);
}


Effect::Effect()
{
    // Add the default hit effect
    onHitEffect = CollisionEffects::defaultHit;
    movementEffect = MovementEffects::defaultMovement;
}