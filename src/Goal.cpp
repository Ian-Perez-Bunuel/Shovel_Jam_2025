#include "../include/Goal.h"

void Goal::init(Vector2 t_pos)
{
    position = t_pos;
}

void Goal::draw()
{
    DrawCircleV(position, radius, BLACK);
}

bool Goal::checkForBall(std::shared_ptr<Projectile> &t_ball)
{
    if (CheckCollisionCircles(t_ball->getPos(), t_ball->getRadius(), position, radius))
    {
        printf("Level Completed");
        return true;
    }

    return false;
}
