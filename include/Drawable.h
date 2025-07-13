#pragma once

#include "raylib.h"
#include "stdio.h"
#include <vector>
#include <memory>

class Drawable
{
public:
    Drawable(Vector2& t_pos, bool& t_active);

    void setAnimations(int t_rowNum, int t_colNum, int t_frameWidth, int t_frameHeight);
    void setTexture(Texture2D& t_tex);

    float getYPos() { return position.y; }
    Texture2D getTexture() const { return *texture; }

    void draw();
private:
    Texture2D* texture;
    Rectangle srcRect;

    Vector2& position;

    bool& active;
    bool animated = false;

    Rectangle dstRect;
    Vector2 origin;

    // Animation
    void animate();
    int rowNum = -1;
    int colNum = -1;
    int frameWidth = -1;
    int frameHeight = -1;

    int currentFrame = 0;
    float frameTimer = 0.0f;
    const float ANIMATION_SPEED = 0.1f; // frame per second
};