#pragma once

#include "raylib.h"
#include "raymath.h"

class Health
{
public: 
    void init(int t_maxHealth);
    void takeDamage(int t_amount);

    void draw(Vector2 t_pos);

private:
    bool alive = false;

    int maxHealth = 0;
    int currentHealth = 0;
};