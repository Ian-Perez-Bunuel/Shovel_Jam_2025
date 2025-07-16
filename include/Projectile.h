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

    void setEffect(Effect& t_effects) { effects = t_effects; }
    
    int getDamage() { return effects.damage; }
    
private:
    void input();
    void release();

    void onCollision(const std::shared_ptr<Obstacle>& t_box, CollisionInfo t_result);

    Vector2 spawnPos;
    Vector2 velocity;
    Vector2 direction;

    Effect effects;
    Texture2D& texture;
    float radius;

    bool moving = false;
};

#include "../include/Obstacle.h"
