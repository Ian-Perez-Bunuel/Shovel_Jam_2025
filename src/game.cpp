#include "../include/game.h"
#include "../include/Pools.h"
#include "../include/Globals.h"

void Game::init()
{
    ProjectilePool::init();
    
    player = std::make_shared<Player>();
    player->init({0, 0}, 25.0f);
    
    PickupPool::init(10, player);

    for (int i = 0; i < PickupPool::PICKUP_POOL_SIZE; i++)
    {
        Vector2 randPos = {rand() % 1000, rand() % 1000};
        PickupPool::pickups[i]->spawn(randPos);
    }

    for (int i = 0; i < ENEMY_AMOUNT; i++)
    {
        enemies.push_back(std::make_shared<Enemy>());
        enemies[i]->init();
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
    renderer->addSprite(player->getWeapon()->getSprite());

    for (std::shared_ptr<Projectile>& proj : ProjectilePool::playerProjectiles)
    {
        renderer->addSprite(proj->getSprite());
    }

    for (std::shared_ptr<Projectile>& proj : ProjectilePool::enemyProjectiles)
    {
        renderer->addSprite(proj->getSprite());
    }

    for (const std::shared_ptr<Pickup>& pickup : PickupPool::pickups)
    {
        renderer->addSprite(pickup->getSprite());
    }

    for (const std::shared_ptr<Enemy>& enemy : enemies)
    {
        renderer->addSprite(enemy->getSprite());
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

    for (const std::shared_ptr<Pickup>& pickup : PickupPool::pickups)
    {
        pickup->draw();
    }
    
    player->draw();

    for (const std::shared_ptr<Enemy>& enemy : enemies)
    {
        enemy->draw();
    }

    for (std::shared_ptr<Projectile>& proj : ProjectilePool::playerProjectiles)
    {
        proj->draw();
    }
    for (std::shared_ptr<Projectile>& proj : ProjectilePool::enemyProjectiles)
    {
        proj->draw();
    }


    // Draw last Besides UI
    renderer->drawAll();

    EndMode2D();
}

void Game::drawUI()
{
    player->drawInventory();

    for (const std::shared_ptr<Enemy>& enemy : enemies)
    {
        enemy->update(player);
    }
}

void Game::update()
{
    mousePos = GetScreenToWorld2D(GetMousePosition(), camera);

    player->update();
    player->checkForPickups();

    for (const std::shared_ptr<Pickup>& pickup : PickupPool::pickups)
    {
        pickup->update();
    }

    camera.target = player->getPos();
}
