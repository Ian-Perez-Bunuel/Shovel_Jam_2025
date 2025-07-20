#include "../include/game.h"
#include "../include/Globals.h"
#include "../include/Floor.h"
#include <ctime>

void Game::init()
{    
    srand(time(NULL));

    ui = std::make_unique<UI>(ball);
    startPos = {150.0f, SCREEN_HEIGHT / 2.0f};

    ballTexture = LoadTexture(PLAYER_PATH"/ball.png");
    ball = std::make_shared<Projectile>(ballTexture, startPos);

    boxTexture = LoadTexture(SPRITE_PATH"/block.png");
    SetTextureWrap(boxTexture, TEXTURE_WRAP_REPEAT);
    // Encase the screen in boxes
    Vector2 pos = {SCREEN_WIDTH / 2.0f, 200.0f};
    walls.push_back(std::make_shared<Obstacle>(pos, YELLOW, boxTexture, false, SCREEN_WIDTH, TILE_SIZE));
    pos = {SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT};
    walls.push_back(std::make_shared<Obstacle>(pos, YELLOW, boxTexture, false, SCREEN_WIDTH, TILE_SIZE));
    pos = {0.0f, SCREEN_HEIGHT / 2.0f + 96};
    walls.push_back(std::make_shared<Obstacle>(pos, YELLOW, boxTexture, false, TILE_SIZE, SCREEN_HEIGHT - 200));
    pos = {SCREEN_WIDTH, SCREEN_HEIGHT / 2.0f + 96};
    walls.push_back(std::make_shared<Obstacle>(pos, YELLOW, boxTexture, false, TILE_SIZE, SCREEN_HEIGHT - 200));

    // Level
    levels.resize(6);
    levels[0] = std::make_shared<Level>(0); // custom level
    levels[1] = std::make_shared<Level>(1);
    levels[2] = std::make_shared<Level>(2);
    levels[3] = std::make_shared<Level>(3);
    levels[4] = std::make_shared<Level>(4);
    levels[5] = std::make_shared<Level>(5);

    currentLevel = 1;
    levels[currentLevel]->init(ball);

    initRenderer();
}

void Game::initRenderer()
{
    renderer = std::make_unique<Renderer>();

    // Give the renderer all the sprites
    renderer->addSprite(ball->getSprite());
}

void Game::draw()
{
    drawGame();

    drawUI();
}

void Game::drawGame()
{
    Floor::drawTiledGrass();
    
    for (std::shared_ptr<Obstacle>& obstacle : walls)
    {
        obstacle->draw();
    }

    levels[currentLevel]->draw();

    ball->draw();

    // Draw last Besides UI
    renderer->drawAll();
}

void Game::drawUI()
{
    // Draw UI
    ui->draw();
}

void Game::update()
{
    if (IsKeyReleased(KEY_ESCAPE))
    {
        currentLevel = 1;
        scene = Scene::MainMenu;
    }

    if (currentLevel != 0 && scene == Scene::LevelMaker)
    {
        currentLevel = 0;
        levels[currentLevel]->init(ball);
    }

    ui->update();

    std::vector<std::shared_ptr<Obstacle>> allObjects;
    // Level objects
    for (std::shared_ptr<Obstacle>& obj : levels[currentLevel]->getObjects())
    {
        allObjects.push_back(obj);
    }
    for (std::shared_ptr<Obstacle>& obj : walls)
    {
        allObjects.push_back(obj);
    }
    ball->update(allObjects);

    if (scene == Scene::LevelMaker)
    {
        levels[currentLevel]->levelEditting();
    }

    if (levels[currentLevel]->update(ball))
    {
        completeLevel();
    }

    checkForLose();
}

void Game::completeLevel()
{
    ball->reset();
    if (currentLevel < levels.size()-1) // dont go out of scope
    {
        ui->reset();

        if (scene == Scene::Game)
        {
            levels[currentLevel]->resetLevel(ball);
            currentLevel++;
        }
        else if (scene == Scene::LevelMaker)
        {
            currentLevel = 0;
            levels[currentLevel]->saveLevel();
        }
                        
        levels[currentLevel]->init(ball);
    }
    else
    {
        scene = Scene::MainMenu;
    }   
}

void Game::checkForLose()
{
    if (ui->getCredits() < 0)
    {
        // Restart level
        ball->reset();
        ui->reset();
        levels[currentLevel]->init(ball);
    }
}