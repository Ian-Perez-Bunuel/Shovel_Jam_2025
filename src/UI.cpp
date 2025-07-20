#include "../include/UI.h"
#include "../include/Globals.h"
#include "../include/Effect.h"

int UI::currentCreditMax;
int UI::credit;

// Movement toggles
Toggle UI::defaultMovement;
Toggle UI::sinMovement;
Toggle UI::randomMovement;
Toggle UI::maxPower;

// Hit toggles
Toggle UI::defaultHit;
Toggle UI::destroyHit;
Toggle UI::noHit;
Toggle UI::stickyHit;

UI::UI(std::shared_ptr<Projectile>& t_ball)
    : ball(t_ball)
{
    background = LoadTexture(UI_PATH"/background.png");

    defaultMovement.init({400, 85}, "Normal - FREE");
    sinMovement.init({400, 115}, "Sin - " + std::to_string(MovementEffects::SIN_COST));
    randomMovement.init({400, 145}, "Random - " + std::to_string(MovementEffects::RANDOM_COST));
    maxPower.init({400, 175}, "MAX POWER - " + std::to_string(MovementEffects::MAX_POWER_COST));

    defaultHit.init({700, 85}, "Normal - FREE");
    stickyHit.init({700, 115}, "Sticky - " + std::to_string(CollisionEffects::STICKY_COST));
    destroyHit.init({700, 145}, "Destroyer - " + std::to_string(CollisionEffects::DESTROY_COST));
    noHit.init({700, 175}, "Slide - " + std::to_string(CollisionEffects::NO_COLLISION_COST));

    credit = MAX_CREDIT;
    currentCreditMax = MAX_CREDIT;

    ballParticles.addColor(particleColor);

    defaultHit.turnOn();
    defaultMovement.turnOn();

    powerUpSound = LoadSound(SOUND_PATH"/powerUp.wav");
    powerDownSound = LoadSound(SOUND_PATH"/powerDown.wav");
}

void UI::draw()
{
    //DrawRectangleV({10, 10}, {SCREEN_WIDTH - 20, SCREEN_HEIGHT * 0.2f}, PURPLE);
    DrawTextureEx(background, {10, 10}, 0, PIXEL_SCALE, WHITE);

    std::string creditText = ("Credit: " + std::to_string(credit));
    DrawText(creditText.c_str(), 25, 25, 50, YELLOW);

    std::string strokesText = ("Strokes: " + std::to_string(ball->strokes));
    DrawText(strokesText.c_str(), 25, 85, 50, WHITE);


    DrawText("W: Increase shot speed", 25, 145, 25, BLACK);
    DrawText("S: Decrease shot speed", 25, 170, 25, BLACK);

    DrawText("Movement", 400, 25, 40, BLACK);
    defaultMovement.draw();
    sinMovement.draw();
    randomMovement.draw();
    maxPower.draw();

    DrawText("Collision", 700, 25, 40, BLACK);
    defaultHit.draw();
    stickyHit.draw();
    destroyHit.draw();
    noHit.draw();

    ballParticles.draw();
}

void UI::update()
{
    input();

    if (credit > currentCreditMax)
    {
        credit = currentCreditMax;
    }

    if (mouseInUI())
    {
        if (IsMouseButtonReleased(0))
        {
            updateMovementToggles();
            updateHitToggles();
        }
    }

    // Particles
    ballParticles.update();
}

bool UI::mouseInUI()
{
    if (GetMousePosition().y <= SCREEN_HEIGHT * 0.2f)
    {
        return true;
    }
    return false;
}


void UI::updateMovementToggles()
{
    bool anyTurnedOff = false;

    if (defaultMovement.mouseCheck(credit, MovementEffects::DEFAULT_COST, anyTurnedOff))
    {
        // Set effect
        ball->setMoveEffect(MovementEffects::defaultMovement);
        // turn off the others
        sinMovement.turnOff(credit, MovementEffects::SIN_COST);
        randomMovement.turnOff(credit, MovementEffects::RANDOM_COST);
        maxPower.turnOff(credit, MovementEffects::MAX_POWER_COST);

        // Particles
        ballParticles.setValues(ball->getPos(), 360, 0);
        ballParticles.implode(5, ball->getRadius() * 2);
    }
    // SIN MOVEMENT
    else if (sinMovement.mouseCheck(credit, MovementEffects::SIN_COST, anyTurnedOff))
    {
        ball->setMoveEffect(MovementEffects::sinMovement);
        defaultMovement.turnOff(credit, MovementEffects::DEFAULT_COST);
        randomMovement.turnOff(credit, MovementEffects::RANDOM_COST);
        maxPower.turnOff(credit, MovementEffects::MAX_POWER_COST);

        // Particles
        ballParticles.setValues(ball->getPos(), 360, 0);
        ballParticles.implode(5, ball->getRadius() * 2);
    }
    // Random movement
    else if (randomMovement.mouseCheck(credit, MovementEffects::RANDOM_COST, anyTurnedOff))
    {
        ball->setMoveEffect(MovementEffects::randomMovement);
        defaultMovement.turnOff(credit, MovementEffects::DEFAULT_COST);
        sinMovement.turnOff(credit, MovementEffects::SIN_COST);
        maxPower.turnOff(credit, MovementEffects::MAX_POWER_COST);

        // Particles
        ballParticles.setValues(ball->getPos(), 360, 0);
        ballParticles.implode(5, ball->getRadius() * 2);
    }
    // Max power
    else if (maxPower.mouseCheck(credit, MovementEffects::MAX_POWER_COST, anyTurnedOff))
    {
        ball->setMoveEffect(MovementEffects::maxMovement);
        defaultMovement.turnOff(credit, MovementEffects::DEFAULT_COST);
        sinMovement.turnOff(credit, MovementEffects::SIN_COST);
        randomMovement.turnOff(credit, MovementEffects::RANDOM_COST);

        // Particles
        ballParticles.setValues(ball->getPos(), 360, 0);
        ballParticles.implode(5, ball->getRadius() * 2);
    }

    if (anyTurnedOff)
    {   
        ball->setMoveEffect(MovementEffects::defaultMovement);

        // Particles
        ballParticles.setValues(ball->getPos(), 360, 0);
        ballParticles.spawn(5);
    }
}

void UI::updateHitToggles()
{
    bool anyTurnedOff = false;

    if (defaultHit.mouseCheck(credit, CollisionEffects::DEFAULT_COST, anyTurnedOff))
    {
        // Set effect
        ball->setHitEffect(CollisionEffects::defaultHit);
        // turn off the others
        destroyHit.turnOff(credit, CollisionEffects::DESTROY_COST);
        stickyHit.turnOff(credit, CollisionEffects::STICKY_COST);
        noHit.turnOff(credit, CollisionEffects::NO_COLLISION_COST);

        // Particles
        ballParticles.setValues(ball->getPos(), 360, 0);
        ballParticles.implode(5, ball->getRadius() * 2);
    }
    else if (destroyHit.mouseCheck(credit, CollisionEffects::DESTROY_COST, anyTurnedOff))
    {
        ball->setHitEffect(CollisionEffects::destroyHit);
        // turn off the others
        defaultHit.turnOff(credit, CollisionEffects::DEFAULT_COST);
        noHit.turnOff(credit, CollisionEffects::NO_COLLISION_COST);
        stickyHit.turnOff(credit, CollisionEffects::STICKY_COST);

        // Particles
        ballParticles.setValues(ball->getPos(), 360, 0);
        ballParticles.implode(5, ball->getRadius() * 2);
    }
    else if (noHit.mouseCheck(credit, CollisionEffects::NO_COLLISION_COST, anyTurnedOff))
    {
        ball->setHitEffect(CollisionEffects::noHit);
        // turn off the others
        defaultHit.turnOff(credit, CollisionEffects::DEFAULT_COST);
        destroyHit.turnOff(credit, CollisionEffects::DESTROY_COST);
        stickyHit.turnOff(credit, CollisionEffects::STICKY_COST);

        // Particles
        ballParticles.setValues(ball->getPos(), 360, 0);
        ballParticles.implode(5, ball->getRadius() * 2);
    }
    else if (stickyHit.mouseCheck(credit, CollisionEffects::STICKY_COST, anyTurnedOff))
    {
        ball->setHitEffect(CollisionEffects::stickyHit);
        // turn off the others
        defaultHit.turnOff(credit, CollisionEffects::DEFAULT_COST);
        destroyHit.turnOff(credit, CollisionEffects::DESTROY_COST);
        noHit.turnOff(credit, CollisionEffects::NO_COLLISION_COST);

        // Particles
        ballParticles.setValues(ball->getPos(), 360, 0);
        ballParticles.implode(5, ball->getRadius() * 2);
    }

    if (anyTurnedOff)
    {   
        ball->setHitEffect(CollisionEffects::defaultHit);

        // Particles
        ballParticles.setValues(ball->getPos(), 360, 0);
        ballParticles.spawn(5);
    }
}
void UI::input()
{
    if (!ball->isMoving())
    {
        if (IsKeyReleased(KEY_W))
        {
            if (credit >= COST_PER_POWER)
            {
                ball->addSpeed(INCREMENT_AMOUNT);
                credit -= COST_PER_POWER;

                ballParticles.setValues(ball->getPos(), 360, 0);
                ballParticles.implode(5, ball->getRadius() * 2);

                float randChange = ((rand() % 4) - 2) / 10.0f;
                SetSoundVolume(powerUpSound, MASTER_VOLUME);
                SetSoundPitch(powerUpSound, 1 + randChange);
                PlaySound(powerUpSound);
            }
        }
        else if (IsKeyReleased(KEY_S))
        {
            if (ball->getSpeed() >= COST_PER_POWER)
            {
                ball->addSpeed(-INCREMENT_AMOUNT);
                credit += COST_PER_POWER;

                ballParticles.setValues(ball->getPos(), 360, 0);
                ballParticles.implode(5, ball->getRadius() * 1.5f);

                float randChange = ((rand() % 4) - 2) / 10.0f;
                SetSoundVolume(powerDownSound, MASTER_VOLUME);
                SetSoundPitch(powerDownSound, 1 + randChange);
                PlaySound(powerDownSound);
            }
        }
    }
}

void UI::reset()
{
    ball->strokes = 0;
    
    defaultHit.turnOff(credit, CollisionEffects::DEFAULT_COST);
    destroyHit.turnOff(credit, CollisionEffects::DESTROY_COST);
    noHit.turnOff(credit, CollisionEffects::NO_COLLISION_COST);
    stickyHit.turnOff(credit, CollisionEffects::STICKY_COST);

    defaultMovement.turnOff(credit, MovementEffects::DEFAULT_COST);
    sinMovement.turnOff(credit, MovementEffects::SIN_COST);
    randomMovement.turnOff(credit, MovementEffects::RANDOM_COST);
    maxPower.turnOff(credit, MovementEffects::MAX_POWER_COST);
    
    currentCreditMax = MAX_CREDIT;
    credit = MAX_CREDIT;
}

void UI::setNewMaxCredits()
{
    currentCreditMax = credit;

    defaultHit.turnOn();
    destroyHit.turnOff(credit, CollisionEffects::DESTROY_COST);
    noHit.turnOff(credit, CollisionEffects::NO_COLLISION_COST);
    stickyHit.turnOff(credit, CollisionEffects::STICKY_COST);

    defaultMovement.turnOn();
    sinMovement.turnOff(credit, MovementEffects::SIN_COST);
    randomMovement.turnOff(credit, MovementEffects::RANDOM_COST);
    maxPower.turnOff(credit, MovementEffects::MAX_POWER_COST);
}

void UI::checkForFail()
{
    if (credit <= 0)
    {
        credit = -1;
    }
}