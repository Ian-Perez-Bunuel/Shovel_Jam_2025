#pragma once

#include "../include/Goal.h"
#include "../include/Obstacle.h"

#include "../include/json.hpp"

using json = nlohmann::json;


class Level
{
public:
    Level(int t_level);
    void init(std::shared_ptr<Projectile>& t_ball);

    void draw();
    void levelEditting();
    bool update(std::shared_ptr<Projectile>& t_ball);

    std::vector<std::shared_ptr<Obstacle>> getObjects() { return obstacles; }
    void saveLevel();
    void resetLevel(std::shared_ptr<Projectile>& t_ball) { levelCompleted = false; loadLevel(t_ball); }
private:
    bool levelCompleted = false;
    int level;

    void loadLevel(std::shared_ptr<Projectile>& t_ball);

    Texture2D boxTexture;

    Vector2 startPos;
    Goal goal;
    std::vector<std::shared_ptr<Obstacle>> obstacles;
};