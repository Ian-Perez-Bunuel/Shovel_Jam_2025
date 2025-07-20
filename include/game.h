#pragma once
#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "stdio.h"
#include <vector>
#include <memory>

#include "../include/Projectile.h"
#include "../include/UI.h"
#include "../include/Renderer.h"
#include "../include/Level.h"

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
    std::unique_ptr<UI> ui;

    Texture2D ballTexture;
    std::shared_ptr<Projectile> ball;

    static const int MAX_OBSTACLES = 100;
    const int TILE_SIZE = 96;
    Texture2D boxTexture;
    std::vector<std::shared_ptr<Obstacle>> walls;

    void completeLevel();
    int currentLevel;
    std::vector<std::shared_ptr<Level>> levels;

    void checkForLose();
    Vector2 startPos;
};

#endif // GAME_H
