#pragma once
#include "raylib.h"

#define SPRITE_PATH     "resources/sprites"
#define LEVELS_PATH     "resources/Levels"
#define PICKUPS_PATH    SPRITE_PATH "/pickups"
#define PLAYER_PATH     SPRITE_PATH "/player"
#define ENEMY_PATH      SPRITE_PATH "/enemy"
#define UI_PATH         SPRITE_PATH "/ui"

static const int SCREEN_WIDTH = 1000;
static const int SCREEN_HEIGHT = 1000;
static const float PIXEL_SCALE = 0.08f;


static const float FRICTION = 0.95f;