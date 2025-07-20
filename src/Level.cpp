#include "../include/Level.h"
#include "../include/Globals.h"
#include <iostream>
#include <fstream>

Level::Level(int t_level)
    : level(t_level)
{
    levelCompleted = false;
}

void Level::init(std::shared_ptr<Projectile>& t_ball)
{
    boxTexture = LoadTexture(SPRITE_PATH"/block.png");
    loadLevel(t_ball);
    t_ball->strokes = 0;
    levelCompleted = false;
}

void Level::draw()
{
    DrawCircleV(startPos, 7, RED);
    goal.draw();

    for (std::shared_ptr<Obstacle>& obj : obstacles)
    {
        obj->draw();
    }
}

// Returns true on level completed
bool Level::update(std::shared_ptr<Projectile>& t_ball)
{
    for (std::shared_ptr<Obstacle>& obj : obstacles)
    {
        obj->update();
    }

    if (goal.checkForBall(t_ball))
    {
        levelCompleted = true;
        t_ball->setActive(false);
    }

    if (levelCompleted)
    {
        if (t_ball->getScale() > 0.0f)
        {
            t_ball->setPos(goal.getPos());
            t_ball->scaleDown();
        }
        else
        {
            return true;
        }
    }

    return false;
}

void Level::levelEditting()
{
    if (IsMouseButtonReleased(1)) // Right click
    {
        for (std::shared_ptr<Obstacle>& obj : obstacles)
        {
            if (CheckCollisionPointRec(GetMousePosition(), obj->getRect()))
            {
                obj->grab();
            }
        }
    }

    // Spawn Block
    if (IsMouseButtonReleased(MOUSE_BUTTON_MIDDLE))
    {
        obstacles.push_back(std::make_shared<Obstacle>(GetMousePosition(), YELLOW, boxTexture, true, 64, 64));
    }

    if (IsKeyReleased(KEY_SPACE))
    {
        goal.init(GetMousePosition());
    }

    if (IsKeyReleased(KEY_E))
    {
        startPos = GetMousePosition();
    }

    // Save with Control+S
    if (IsKeyDown(KEY_S) && IsKeyDown(KEY_LEFT_CONTROL))
    {
        printf("\nSAVED LEVEL\n\n");
        saveLevel();
    }   

    for (std::shared_ptr<Obstacle>& obj : obstacles)
    {
        obj->update();
    }
}

void Level::saveLevel()
{
    json j;

    // Save starting position
    j["start"] = {
        {"x", startPos.x},
        {"y", startPos.y}
    };

    // Save goal position
    j["goal"] = {
        {"x", goal.getPos().x},
        {"y", goal.getPos().y}
    };

    // Save obstacles
    for (const auto& obj : obstacles) 
    {
        j["obstacles"].push_back({
            {"x", obj->getPos().x},
            {"y", obj->getPos().y},
            {"width", obj->getRect().width},
            {"height", obj->getRect().height}
        });
    }

    std::filesystem::create_directories(LEVELS_PATH);

    std::ofstream file(LEVELS_PATH "/level"+std::to_string(level)+".json");
    if (!file) 
    {
        printf("Failed to open file for saving.\n");
        return;
    }

    file << j.dump(4); // pretty-print with indent
}

void Level::loadLevel(std::shared_ptr<Projectile>& t_ball)
{
    std::ifstream file(LEVELS_PATH "/level"+std::to_string(level)+".json");
    if (!file) 
    {
        std::cerr << "Failed to open level file for loading.\n";
        return;
    }

    json j;
    file >> j;

    // Load goal position
    goal.init({ j["goal"]["x"], j["goal"]["y"] });

    startPos = {j["start"]["x"], j["start"]["y"]};
    t_ball->setPos(startPos);

    // Load obstacles
    obstacles.clear();
    for (const auto& item : j["obstacles"]) 
    {
        Vector2 pos = { item["x"], item["y"] };
        float width = item["width"];
        float height = item["height"];
        auto obstacle = std::make_shared<Obstacle>(pos, YELLOW, boxTexture, true, width, height);
        obstacles.push_back(obstacle);
    }
}
