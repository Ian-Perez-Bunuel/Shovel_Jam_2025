#include "../include/game.h"
#include "../include/Globals.h"

void Game::init()
{
    player = std::make_shared<Player>();
    player->init({0, 0}, 25.0f);

    for (int i = 0; i < PICKUP_AMOUNT; i++)
    {
        pickups.push_back(std::make_shared<Pickup>());
        pickups[i]->init(10, player);

        Vector2 randPos = {rand() % 1000, rand() % 1000};
        pickups[i]->spawn(randPos);
    }

    // --- Camera setup ---
    camera.target = player->getPos();                 
    camera.offset = { SCREEN_WIDTH/2, SCREEN_HEIGHT/2 }; 
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;   


    initRenderer();
}

void Game::initRenderer()
{
    renderer = std::make_unique<Renderer>();
    // Give the renderer all the sprites
    renderer->addSprite(player->getSprite());
    renderer->addSprite(player->getWeapon().getSprite());

    for (const std::shared_ptr<Pickup>& pickup : pickups)
    {
        renderer->addSprite(pickup->getSprite());
    }
}

void Game::draw()
{
    drawGame();
    drawUI();
}

void Game::drawGame()
{
    BeginMode2D(camera);

    // for (const std::shared_ptr<Pickup>& pickup : pickups)
    // {
    //     pickup->draw();
    // }
    
    //player->draw();


    // Draw last Besides UI
    renderer->drawAll();

    EndMode2D();
}

void Game::drawUI()
{
    player->drawInventory();
}

void Game::update()
{
    mousePos = GetScreenToWorld2D(GetMousePosition(), camera);

    player->update();
    player->checkForPickups(pickups);

    for (const std::shared_ptr<Pickup>& pickup : pickups)
    {
        pickup->update();
    }

    camera.target = player->getPos();
}
