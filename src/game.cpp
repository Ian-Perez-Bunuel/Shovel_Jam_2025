#include "../include/game.h"
#include "../include/Globals.h"

void Game::init()
{    
    startPos = {150.0f, SCREEN_HEIGHT / 2.0f};

    ballTexture = LoadTexture(PLAYER_PATH"/ball.png");
    ball = std::make_shared<Projectile>(ballTexture, startPos);

    boxTexture = LoadTexture(SPRITE_PATH"/block.png");
    SetTextureWrap(boxTexture, TEXTURE_WRAP_REPEAT);
    // Encase the screen in boxes
    Vector2 pos = {SCREEN_WIDTH / 2.0f, 0.0f};
    obstacles.push_back(std::make_shared<Obstacle>(pos, YELLOW, boxTexture, SCREEN_WIDTH, TILE_SIZE));
    pos = {SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT};
    obstacles.push_back(std::make_shared<Obstacle>(pos, YELLOW, boxTexture, SCREEN_WIDTH, TILE_SIZE));
    pos = {0.0f, SCREEN_HEIGHT / 2.0f};
    obstacles.push_back(std::make_shared<Obstacle>(pos, YELLOW, boxTexture, TILE_SIZE, SCREEN_HEIGHT));
    pos = {SCREEN_WIDTH, SCREEN_HEIGHT / 2.0f};
    obstacles.push_back(std::make_shared<Obstacle>(pos, YELLOW, boxTexture, TILE_SIZE, SCREEN_HEIGHT));

    pos = {SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};
    obstacles.push_back(std::make_shared<Obstacle>(pos, YELLOW, boxTexture, TILE_SIZE, TILE_SIZE));

    initRenderer();
}

void Game::initRenderer()
{
    renderer = std::make_unique<Renderer>();

    // Give the renderer all the sprites
    renderer->addSprite(ball->getSprite());

    for (std::shared_ptr<Obstacle>& obstacle : obstacles)
    {
        renderer->addSprite(obstacle->getSprite());
    }
}

void Game::draw()
{
    drawGame();
    drawUI();
}

void Game::drawGame()
{
    for (std::shared_ptr<Obstacle>& obstacle : obstacles)
    {
        obstacle->draw();
    }

    ball->draw();

    // Draw last Besides UI
    renderer->drawAll();
}

void Game::drawUI()
{

}

void Game::update()
{
    ball->update(obstacles);
   // ball->checkCollisions(obstacles);
}
