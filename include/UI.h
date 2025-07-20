#pragma once

#include "raylib.h"
#include <memory>
#include <vector>
#include "../include/Toggle.h"
#include "../include/Projectile.h"
#include "../include/ParticleSpawner.h"

class UI
{
public:
    UI(std::shared_ptr<Projectile>& t_ball);
    void draw();
    void update();

    void reset();

    static bool mouseInUI();

    int getCredits() { return credit; }
    static void setNewMaxCredits();
    static void checkForFail();
private:
    void input();
    Texture2D background;

    void updateMovementToggles();
    void updateHitToggles();

    // Movement toggles
    static Toggle defaultMovement;
    static Toggle sinMovement;
    static Toggle randomMovement;
    static Toggle maxPower;

    // Hit toggles
    static Toggle defaultHit;
    static Toggle destroyHit;
    static Toggle noHit;
    static Toggle stickyHit;

    const int COST_PER_POWER = 5;

    const int MAX_CREDIT = 100;
    static int currentCreditMax;
    static int credit;

    std::shared_ptr<Projectile>& ball;

    Color particleColor = {226, 255, 230, 255};
    ParticleSpawner ballParticles;

    Sound powerUpSound;
    Sound powerDownSound;
    Sound addEffectSound;
};