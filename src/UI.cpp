#include "../include/UI.h"
#include "../include/Globals.h"
#include "../include/Effect.h"


UI::UI(std::shared_ptr<Projectile>& t_ball)
    : ball(t_ball)
{
    background = LoadTexture(UI_PATH"/background.png");

    defaultMovement.init({400, 85}, "Normal - FREE");
    sinMovement.init({400, 115}, "Sin - " + std::to_string(MovementEffects::SIN_COST));
    randomMovement.init({400, 145}, "Random - " + std::to_string(MovementEffects::RANDOM_COST));
    maxPower.init({400, 175}, "MAX POWER - " + std::to_string(MovementEffects::MAX_POWER_COST));

    defaultHit.init({700, 85}, "Normal - FREE");
    destroyHit.init({700, 115}, "Destroyer - " + std::to_string(CollisionEffects::DESTROY_COST));
    noHit.init({700, 145}, "Slide - " + std::to_string(CollisionEffects::NO_COLLISION_COST));

    credit = MAX_CREDIT;
}

void UI::draw()
{
    DrawRectangleV({10, 10}, {SCREEN_WIDTH - 20, SCREEN_HEIGHT * 0.2f}, PURPLE);

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
    destroyHit.draw();
    noHit.draw();
}

void UI::update()
{
    input();

    if (credit > MAX_CREDIT)
    {
        credit = MAX_CREDIT;
    }

    if (mouseInUI())
    {
        if (IsMouseButtonReleased(0))
        {
            updateMovementToggles();
            updateHitToggles();
        }
    }
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
    if (defaultMovement.mouseCheck(credit, MovementEffects::DEFAULT_COST))
    {
        // Set effect
        ball->setMoveEffect(MovementEffects::defaultMovement);
        // turn off the others
        sinMovement.turnOff(credit, MovementEffects::SIN_COST);
        randomMovement.turnOff(credit, MovementEffects::RANDOM_COST);
        maxPower.turnOff(credit, MovementEffects::MAX_POWER_COST);
    }
    // SIN MOVEMENT
    else if (sinMovement.mouseCheck(credit, MovementEffects::SIN_COST))
    {
        ball->setMoveEffect(MovementEffects::sinMovement);
        defaultMovement.turnOff(credit, MovementEffects::DEFAULT_COST);
        randomMovement.turnOff(credit, MovementEffects::RANDOM_COST);
        maxPower.turnOff(credit, MovementEffects::MAX_POWER_COST);
    }
    // Random movement
    else if (randomMovement.mouseCheck(credit, MovementEffects::RANDOM_COST))
    {
        ball->setMoveEffect(MovementEffects::randomMovement);
        defaultMovement.turnOff(credit, MovementEffects::DEFAULT_COST);
        sinMovement.turnOff(credit, MovementEffects::SIN_COST);
        maxPower.turnOff(credit, MovementEffects::MAX_POWER_COST);
    }
    // Max power
    else if (maxPower.mouseCheck(credit, MovementEffects::MAX_POWER_COST))
    {
        ball->setMoveEffect(MovementEffects::maxMovement);
        defaultMovement.turnOff(credit, MovementEffects::DEFAULT_COST);
        sinMovement.turnOff(credit, MovementEffects::SIN_COST);
        randomMovement.turnOff(credit, MovementEffects::RANDOM_COST);
    }

}

void UI::updateHitToggles()
{
    if (defaultHit.mouseCheck(credit, CollisionEffects::DEFAULT_COST))
    {
        // Set effect
        ball->setHitEffect(CollisionEffects::defaultHit);
        // turn off the others
        destroyHit.turnOff(credit, CollisionEffects::DESTROY_COST);
        noHit.turnOff(credit, CollisionEffects::NO_COLLISION_COST);
    }
    else if (destroyHit.mouseCheck(credit, CollisionEffects::DESTROY_COST))
    {
        ball->setHitEffect(CollisionEffects::destroyHit);
        // turn off the others
        defaultHit.turnOff(credit, CollisionEffects::DEFAULT_COST);
        noHit.turnOff(credit, CollisionEffects::NO_COLLISION_COST);
    }
    else if (noHit.mouseCheck(credit, CollisionEffects::NO_COLLISION_COST))
    {
        ball->setHitEffect(CollisionEffects::noHit);
        // turn off the others
        defaultHit.turnOff(credit, CollisionEffects::DEFAULT_COST);
        destroyHit.turnOff(credit, CollisionEffects::DESTROY_COST);
    }
}
void UI::input()
{
    if (IsKeyReleased(KEY_W))
    {
        if (credit >= INCREMENT_AMOUNT)
        {
           ball->addSpeed(INCREMENT_AMOUNT);
            credit -= COST_PER_POWER;
        }
    }
    else if (IsKeyReleased(KEY_S))
    {
        if (ball->getSpeed() >= INCREMENT_AMOUNT)
        {
            ball->addSpeed(-INCREMENT_AMOUNT);
            credit += COST_PER_POWER;
        }
    }
}

void UI::reset()
{
    ball->strokes = 0;
    
    defaultHit.turnOff(credit, CollisionEffects::DEFAULT_COST);
    destroyHit.turnOff(credit, CollisionEffects::DESTROY_COST);
    noHit.turnOff(credit, CollisionEffects::NO_COLLISION_COST);

    defaultMovement.turnOff(credit, MovementEffects::DEFAULT_COST);
    sinMovement.turnOff(credit, MovementEffects::SIN_COST);
    randomMovement.turnOff(credit, MovementEffects::RANDOM_COST);
    maxPower.turnOff(credit, MovementEffects::MAX_POWER_COST);
    
    credit = MAX_CREDIT;
}