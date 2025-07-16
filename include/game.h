#pragma once
#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "stdio.h"
#include <vector>
#include <memory>

#include "../include/Player.h"
#include "../include/Enemy.h"
#include "../include/Pickup.h"
#include "../include/Renderer.h"

class Game
{
public:
    void init();
    void draw();
    void update();

private:
    void drawGame();
    void drawUI();

    void initRenderer();
    std::unique_ptr<Renderer> renderer;

    std::shared_ptr<Player> player;
    std::vector<std::shared_ptr<Enemy>> enemies;

    Camera2D camera;


    // TEMP
    const int PICKUP_AMOUNT = 100;
    const int ENEMY_AMOUNT = 1;
};

#endif // GAME_H
