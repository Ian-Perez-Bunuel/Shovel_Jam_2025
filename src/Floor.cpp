#include "../include/Floor.h"
#include "../include/Globals.h"

Texture2D Floor::bg;
std::vector<std::vector<int>> Floor::tileRotations;

void Floor::init()
{
    bg = LoadTexture(SPRITE_PATH"/grass.png");
    initTileRotations();
}

void Floor::initTileRotations()
{
    int tileWidth = bg.width * PIXEL_SCALE;
    int tileHeight = bg.height * PIXEL_SCALE;

    int rows = SCREEN_HEIGHT / tileHeight + 1;
    int cols = SCREEN_WIDTH / tileWidth + 1;

    tileRotations.resize(rows);
    for (int y = 0; y < rows; ++y)
    {
        tileRotations[y].resize(cols);
        for (int x = 0; x < cols; ++x)
        {
            tileRotations[y][x] = GetRandomValue(0, 3) * 90;  // 0, 90, 180, 270 degrees
        }
    }
}

void Floor::drawTiledGrass()
{
    int tileWidth = bg.width * PIXEL_SCALE;
    int tileHeight = bg.height * PIXEL_SCALE;

    int rows = tileRotations.size();
    int cols = tileRotations[0].size(); // assuming non-empty

    for (int y = 0; y < rows; ++y)
    {
        for (int x = 0; x < cols; ++x)
        {
            int angleDeg = tileRotations[y][x];

            Rectangle source = { 0, 0, (float)bg.width, (float)bg.height };

            Rectangle dest = {
                x * tileWidth + tileWidth / 2.0f,
                y * tileHeight + tileHeight / 2.0f,
                (float)tileWidth,
                (float)tileHeight
            };

            Vector2 origin = { tileWidth / 2.0f, tileHeight / 2.0f };

            DrawTexturePro(bg, source, dest, origin, (float)angleDeg, WHITE);
        }
    }
}