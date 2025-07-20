#pragma once

#include "raylib.h"
#include "stdio.h"

#include "../include/Effect.h"
#include "../include/GameObject.h"
#include "../include/ParticleSpawner.h"

class Obstacle;

class Projectile : public GameObject
{
    friend CollisionEffects;
    friend MovementEffects;
public:
    Projectile(Texture2D& t_texture, Vector2 t_pos);
    float getRadius() const { return radius; }
    bool isMoving() { return moving; }

    void update(const std::vector<std::shared_ptr<Obstacle>>& obstacles);
    void draw() override;

    void setMoveEffect(movement t_effect) { effects.movementEffect = t_effect; }
    void setHitEffect(onHit t_effect) { effects.onHitEffect= t_effect; }

    int getSpeed() { return effects.shotSpeed; }
    void addSpeed(int t_amount) { effects.shotSpeed += t_amount; }

    void setPos(Vector2 t_pos) { position = t_pos; }

    void reset();
    float getScale() { return scale; }
    void scaleDown() { scale -= 0.08f; }

    void setActive(bool t_newState) { active = t_newState; }

    int strokes;
    
private:
    void input();
    void release();

    void onCollision(const std::shared_ptr<Obstacle>& t_box, CollisionInfo t_result);
    void doneStepping();

    Vector2 spawnPos;
    Vector2 baseVelocity;
    Vector2 effectVelocity;
    Vector2 combinedVelocity;

    Vector2 direction;
    float time = 0.0f;

    Effect effects;
    Texture2D& texture;
    float radius;

    bool moving = false;

    float scale = 1;

    void trailTimer();
    const float TIME_BETWEEN_PARTICLES = 0.02f;
    float trailCounter = 0.0f;
    const Color lightTrail = {102, 140, 157, 255};
    const Color medTrail = {76, 72, 124, 255};
    const Color darkTrail = {65, 49, 100, 255};
    ParticleSpawner trail;
    float oppositeDirection;

    Sound collisionSound;
};

#include "../include/Obstacle.h"
