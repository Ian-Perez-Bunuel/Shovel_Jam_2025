#pragma once

#include "raylib.h"
#include <memory>
#include <vector>
#include "../include/Toggle.h"
#include "../include/Projectile.h"

class UI
{
public:
    UI(std::shared_ptr<Projectile>& t_ball);
    void draw();
    void update();

    void reset();

    static bool mouseInUI();

private:
    void input();
    Texture2D background;

    void updateMovementToggles();
    void updateHitToggles();

    // Movement toggles
    Toggle defaultMovement;
    Toggle sinMovement;
    Toggle randomMovement;
    Toggle maxPower;

    // Hit toggles
    Toggle defaultHit;
    Toggle destroyHit;
    Toggle noHit;

    const int COST_PER_POWER = 10;

    const int MAX_CREDIT = 100;
    int credit;

    std::shared_ptr<Projectile>& ball;
};