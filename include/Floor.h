#pragma once

#include "raylib.h"
#include "stdio.h"
#include <vector>

class Floor
{
public:
    static void init();
    static void drawTiledGrass();
    static void initTileRotations();
    static std::vector<std::vector<int>> tileRotations;
    static Texture2D bg;
};