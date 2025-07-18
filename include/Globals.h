#pragma once
#include "raylib.h"

#define SPRITE_PATH     "resources/sprites"
#define PICKUPS_PATH    SPRITE_PATH "/pickups"
#define PLAYER_PATH     SPRITE_PATH "/player"
#define ENEMY_PATH      SPRITE_PATH "/enemy"

static const int SCREEN_WIDTH = 1000;
static const int SCREEN_HEIGHT = 800;
static const int PIXEL_SCALE = 2;
static const int INVENTORY_PIXEL_SCALE = 4;


static const float FRICTION = 0.95f;