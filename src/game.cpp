#include "../include/game.h"

void Game::init()
{
    player = std::make_shared<Player>();
    player->init({0, 0}, 25.0f);

    for (int i = 0; i < PICKUP_AMOUNT; i++)
    {
        pickups.push_back(std::make_shared<Pickup>());
        pickups[i]->init(10, player);
    }
}

void Game::draw()
{
    for (const std::shared_ptr<Pickup> pickup : pickups)
    {
        pickup->draw();
    }

    player->draw();
}

void Game::update()
{
    player->update();

    if (IsMouseButtonReleased(0))
    {
        for (const std::shared_ptr<Pickup> pickup : pickups)
        {
            if (!pickup->isActive())
            {
                printf("\nSPAWN at: %f, %f\n\n", GetMousePosition().x, GetMousePosition().y);
                pickup->spawn(GetMousePosition());
                break;
            }
        }
    }

    for (const std::shared_ptr<Pickup> pickup : pickups)
    {
        pickup->update();
    }
}
