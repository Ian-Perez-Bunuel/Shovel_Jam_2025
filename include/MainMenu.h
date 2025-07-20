#pragma once

#include "../include/Button.h"

class MainMenu
{
public:
    void init();
    void draw();
    void update();

private:
    void playGame();
    Texture2D playTexture;
    Button playButton;

    void customGame();
    Texture2D customLevelTexture;
    Button customLevelButton;

    Texture2D logo;
    float logoRotation = 0;

    const int FONT_SIZE = 45;
    Vector2 descriptionPos;
    const std::string PLAY_DESC = "Here you will play 5 custom made levels";
    std::vector<std::string> LEVEL_EDITOR_DESC;
};