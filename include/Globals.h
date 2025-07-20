#pragma once
#include "raylib.h"

#define SPRITE_PATH     "resources/sprites"
#define SOUND_PATH     "resources/Sounds"
#define LEVELS_PATH     "resources/Levels"
#define PICKUPS_PATH    SPRITE_PATH "/pickups"
#define PLAYER_PATH     SPRITE_PATH "/player"
#define ENEMY_PATH      SPRITE_PATH "/enemy"
#define UI_PATH         SPRITE_PATH "/ui"

static const int SCREEN_WIDTH = 1000;
static const int SCREEN_HEIGHT = 1000;
static const float PIXEL_SCALE = 2;

enum class Scene
{
    MainMenu,
    Game,
    LevelMaker
};
inline Scene scene = Scene::MainMenu;

static const float FRICTION = 0.95f;

static const Color WALL_COLOR = {195, 166, 140, 255};

// Volume: 0.0f to 1.0f
inline float MASTER_VOLUME = 0.5f;