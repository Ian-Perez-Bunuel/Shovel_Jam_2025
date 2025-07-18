#include "raylib.h"
#include "stdio.h"

#include "../include/game.h"
#include "../include/Globals.h"

// Specific include for build_web
#if defined(WEB_BUILD)
#include <emscripten/emscripten.h>
#endif

void GameLoop(void);

Game game;


int main(void)
{

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib StarterKit GPPI");

    SetExitKey(KEY_BACKSPACE);

    // Initialise Game
    game.init();

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

int counter = 0;
char message[11];

void GameLoop(void)
{
    BeginDrawing();

    // Update Game Data
    // Should be outside BeginDrawing(); and EndDrawing();
    game.update();

    ClearBackground(BLACK);

    // Draw the Game Objects
    game.draw();
    DrawFPS(0, 0);

    counter++;

    EndDrawing();
}
