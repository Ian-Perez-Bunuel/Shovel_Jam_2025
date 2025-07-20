#pragma once

#include "raylib.h"
#include "stdio.h"

#include "../include/Effect.h"
#include "../include/GameObject.h"

class Obstacle;

class Projectile : public GameObject
{
    friend CollisionEffects;
    friend MovementEffects;
public:
    Projectile(Texture2D& t_texture, Vector2 t_pos);
    float getRadius() const { return radius; }

    void shoot(Effect& t_effects, Vector2 t_dir);

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
};

#include "../include/Obstacle.h"
