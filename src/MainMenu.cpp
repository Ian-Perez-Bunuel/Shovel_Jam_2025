#include "../include/MainMenu.h"
#include "../include/Globals.h"
#include "../include/Floor.h"

void MainMenu::init()
{
    playTexture = LoadTexture(UI_PATH"/playButton.png");
    customLevelTexture = LoadTexture(UI_PATH"/customLevelButton.png");
    logo = LoadTexture(SPRITE_PATH"/logo.png");

    float playWidth = 300;
    float playHeight = 150;
    Vector2 playPos = {SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f - 100};
    playButton.init(playPos, playWidth, playHeight, "Play", playTexture);

    float customWidth = 500;
    float customHeight = 150;
    Vector2 customPos = {SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f + 100};
    customLevelButton.init(customPos, customWidth, customHeight, "Level Creator", customLevelTexture);

    descriptionPos = {SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f + 225};

    LEVEL_EDITOR_DESC.push_back("Here you can make a custom level.");
    LEVEL_EDITOR_DESC.push_back("This level is stored in your files as level0.json,");
    LEVEL_EDITOR_DESC.push_back("Meaning you can send it to friends.");
    LEVEL_EDITOR_DESC.push_back("Controls:");
    LEVEL_EDITOR_DESC.push_back("Middle mouse: Place block");
    LEVEL_EDITOR_DESC.push_back("Right click: Pickup block");
    LEVEL_EDITOR_DESC.push_back("While picked up:");
    LEVEL_EDITOR_DESC.push_back("Side Arrows: Control width - Up/Down Arrows: Control height");
    LEVEL_EDITOR_DESC.push_back("Level is auto-saved after potting the ball or with control + S");
}


void MainMenu::draw()
{
    Floor::drawTiledGrass();

    playButton.draw();
    if (playButton.isHovering())
    {
        // Display description
        int textWidth = MeasureText(PLAY_DESC.c_str(), FONT_SIZE);
        int textHeight = FONT_SIZE;

        DrawText(
            PLAY_DESC.c_str(),
            descriptionPos.x - textWidth / 2,
            descriptionPos.y - textHeight / 2,
            FONT_SIZE,
            WHITE
        );
    } 

    customLevelButton.draw();
    if (customLevelButton.isHovering())
    {
        int currentY = 0;
        // Display description
        for (std::string desc : LEVEL_EDITOR_DESC)
        {
            int textWidth = MeasureText(desc.c_str(), 30);
            int textHeight = 30;

            DrawText(
                desc.c_str(),
                descriptionPos.x - textWidth / 2,
                (descriptionPos.y - textHeight / 2) + currentY,
                30,
                WHITE
            );

            currentY += 32;
        }
    }   


    DrawTextureEx(logo, {-225, 25}, logoRotation, 3, WHITE);
}

void MainMenu::update()
{
    if (playButton.checkForMouse())
    {
        if (IsMouseButtonReleased(0))
        {
            playGame();
        }
    }

    if (customLevelButton.checkForMouse())
    {
        if (IsMouseButtonReleased(0))
        {
            customGame();
        }
    }
}

void MainMenu::playGame()
{
    scene = Scene::Game;
}

void MainMenu::customGame()
{
    scene = Scene::LevelMaker;
}