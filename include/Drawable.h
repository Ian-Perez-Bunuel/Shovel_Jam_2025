#pragma once

#include "raylib.h"
#include "stdio.h"
#include <vector>
#include <memory>

class Drawable
{
public:
    Drawable(Vector2& t_pos, bool& t_isDrawing);

    void setTexture(Texture2D& t_tex);

    float getYPos() { return position.y; }
    Texture2D getTexture() const { return *texture; }

    void draw();
private:
    Texture2D* texture;
    Rectangle srcRect;

    Vector2& position;

    bool& active;
};