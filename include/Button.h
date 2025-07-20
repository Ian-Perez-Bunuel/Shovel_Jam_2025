#pragma once

#include "raylib.h"
#include "stdio.h"
#include <vector>
#include <memory>
#include <string>

class Button
{
public:
    void init(Vector2 t_pos, float t_width, float t_height, std::string t_text, Texture2D t_texture);
    void draw();
    bool checkForMouse();

    bool isHovering() { return hovering; }

private:
    Texture2D texture;
    Rectangle srcRect;
    Rectangle dstRect;
    Vector2 origin;

    Vector2 position;
    Rectangle rect;
    float baseWidth;
    float baseHeight;

    bool hovering = false;

    std::string text;
    int fontSize = 60;
    int textWidth;
    int textHeight;

    float scale = 1;
    static const float MAX_SCALE;
    static const float SCALE_PER_FRAME;
};