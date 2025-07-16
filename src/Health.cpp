#include "../include/Health.h"
#include "raylib.h"
#include "raymath.h"

void Health::init(int t_maxHealth)
{
    maxHealth = t_maxHealth;
    currentHealth = maxHealth;

    alive = true;
}

void Health::takeDamage(int t_amount)
{
    if (t_amount < currentHealth)
    {
        currentHealth -= t_amount;
    }
    else
    {
        currentHealth = 0;
        alive = false;
    }
}

void Health::draw(Vector2 t_pos)
{
    // Health container
    DrawRectangleV(t_pos, {(float)maxHealth, maxHealth / 4.0f}, GRAY);
    DrawRectangleV(t_pos, {(float)currentHealth, maxHealth / 4.1f}, GREEN);
}