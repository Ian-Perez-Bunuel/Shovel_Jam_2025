#include "raylib.h"
#include "stdio.h"

#include "../include/game.h"
#include "../include/MainMenu.h"
#include "../include/Globals.h"
#include "../include/Floor.h"
#include "../include/SoundChanger.h"

// Specific include for build_web
#if defined(WEB_BUILD)
#include <emscripten/emscripten.h>
#endif

void GameLoop(void);

Game game;
MainMenu mainMenu;
SoundChanger soundChanger;

Sound clickSound;

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib StarterKit GPPI");

    InitAudioDevice();
    SetExitKey(KEY_BACKSPACE);

    // Initialise Game
    Floor::init();
    game.init();
    mainMenu.init();
    soundChanger.init();


    clickSound = LoadSound(SOUND_PATH"/click.wav");

    // For web builds, do not use WindowShouldClose
    // see https://github.com/raysan5/raylib/wiki/Working-for-Web-(HTML5)#41-avoid-raylib-whilewindowshouldclose-loop

#if defined(WEB_BUILD)
    emscripten_set_main_loop(GameLoop, 0, 1);
#else
    SetTargetFPS(60);
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Call GameLoop
        GameLoop();
    }
#endif


    CloseWindow();

    return 0;
}


void GameLoop(void)
{
    soundChanger.checkForMouse();

    if (IsMouseButtonReleased(0))
    {
        float randChange = ((rand() % 4) - 2) / 10.0f;
        SetSoundVolume(clickSound, MASTER_VOLUME);
        SetSoundPitch(clickSound, 1 + randChange);
        PlaySound(clickSound);
    }

    if (scene == Scene::MainMenu)
    {
        mainMenu.update();
    }
    else if (scene == Scene::Game || scene == Scene::LevelMaker)
    {
        game.update();
    }

    BeginDrawing();

    ClearBackground(GREEN);

    // Draw the Game Objects
    if (scene == Scene::MainMenu)
    {
        mainMenu.draw();
    }
    else if (scene == Scene::Game || scene == Scene::LevelMaker)
    {
        game.draw();
    }
    //DrawFPS(0, 0);

    soundChanger.draw();

    EndDrawing();
}
