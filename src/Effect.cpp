#include "../include/Effect.h"
#include "../include/Globals.h"
#include "stdio.h"

// Costs of effects
// Hit
const int CollisionEffects::DEFAULT_COST = 0;
const int CollisionEffects::STICKY_COST = 15;
const int CollisionEffects::DESTROY_COST = 20;
const int CollisionEffects::NO_COLLISION_COST = 70;

// Move
const int MovementEffects::DEFAULT_COST = 0;
const int MovementEffects::SIN_COST = 10;
const int MovementEffects::RANDOM_COST = 20;
const int MovementEffects::MAX_POWER_COST = 50;


Effect::Effect()
{
    // Add the default hit effect
    onHitEffect = CollisionEffects::defaultHit;
    movementEffect = MovementEffects::defaultMovement;
}

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
            t_projectile->baseVelocity.x *= -1;
            t_projectile->effectVelocity.x *= -1;
            break;
        case CollisionSide::SIDE_RIGHT:
            t_projectile->baseVelocity.x *= -1;
            t_projectile->effectVelocity.x *= -1;
            break;
        case CollisionSide::SIDE_TOP:
            t_projectile->baseVelocity.y *= -1;
            t_projectile->effectVelocity.y *= -1;
            break;
        case CollisionSide::SIDE_BOTTOM:
            t_projectile->baseVelocity.y *= -1;
            t_projectile->effectVelocity.y *= -1;
            break;
        default:
            // no collision
            break;
    }
}

void CollisionEffects::destroyHit(Projectile *t_projectile, const std::shared_ptr<Obstacle> &t_box, CollisionInfo t_result)
{
    switch(t_result.side)
    {
        case CollisionSide::SIDE_LEFT:   // hit the left side of the box
            t_projectile->baseVelocity.x *= -1;
            t_projectile->effectVelocity.x *= -1;
            break;
        case CollisionSide::SIDE_RIGHT:
            t_projectile->baseVelocity.x *= -1;
            t_projectile->effectVelocity.x *= -1;
            break;
        case CollisionSide::SIDE_TOP:
            t_projectile->baseVelocity.y *= -1;
            t_projectile->effectVelocity.y *= -1;
            break;
        case CollisionSide::SIDE_BOTTOM:
            t_projectile->baseVelocity.y *= -1;
            t_projectile->effectVelocity.y *= -1;
            break;
        default:
            // no collision
            break;
    }

    //Destroy hit block
    t_box->destroy();
}

void CollisionEffects::noHit(Projectile *t_projectile, const std::shared_ptr<Obstacle> &t_box, CollisionInfo t_result)
{
}

void CollisionEffects::stickyHit(Projectile *t_projectile, const std::shared_ptr<Obstacle> &t_box, CollisionInfo t_result)
{
    t_projectile->baseVelocity = {0, 0};
    t_projectile->effectVelocity = {0, 0};
}

// ------------------- MOVEMENT ---------------------



void MovementEffects::defaultMovement(Projectile* t_projectile)
{
    t_projectile->effectVelocity = t_projectile->baseVelocity;
}

void MovementEffects::sinMovement(Projectile *t_projectile)
{
    // axis
    Vector2 dir = Vector2Normalize(t_projectile->baseVelocity);
    Vector2 perp = { -dir.y, dir.x };

    // sine parameters
    float frequency = 1.0f;//* Vector2Length(Vector2Normalize(t_projectile->velocity));
    float amplitude = 0.2f * Normalize(Vector2Length(t_projectile->baseVelocity), 0, 1);
    float omega = 2*PI*frequency;

    float waveVelMag = amplitude * omega * cosf(omega * t_projectile->time);
    t_projectile->effectVelocity = Vector2Scale(perp, waveVelMag);
}

void MovementEffects::randomMovement(Projectile *t_projectile)
{
    // axis
    Vector2 dir = Vector2Normalize(t_projectile->baseVelocity);
    Vector2 perp = { -dir.y, dir.x };

    // Scaled to shot speed
    float randomness = 0.5f * Normalize(Vector2Length(t_projectile->baseVelocity), 0, 1);

    float randOffset = ((float)GetRandomValue(-100, 100) / 25.0f) * randomness;

    // apply random offset in the perpendicular direction
    t_projectile->effectVelocity = Vector2Scale(perp, randOffset);
}

void MovementEffects::maxMovement(Projectile *t_projectile)
{
    t_projectile->effectVelocity = Vector2Scale(t_projectile->baseVelocity, 100);
}