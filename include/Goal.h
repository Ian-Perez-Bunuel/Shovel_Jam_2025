#pragma once

#include "raylib.h"
#include "stdio.h"

#include "../include/Projectile.h"
#include "../include/ParticleSpawner.h"

class Goal
{
public:
    void init(Vector2 t_pos);

    void draw();
    bool checkForBall(std::shared_ptr<Projectile>& t_ball);

    Vector2 getPos() { return position; }

private:
    Texture2D texture;
    Rectangle source;
    Rectangle dest;
    Vector2 origin;

    Vector2 position;
    float radius = 10.0f;

    ParticleSpawner onEnterParticles;

    Sound levelCompleteSound;
};