#pragma once

#include "raylib.h"
#include <vector>
#include <memory>


class Pickup;

class Cell
{
public:
    Cell(Vector2 t_pos);

    static Vector2 getSize() { return SIZE; }
    bool isEmpty() { return empty; }
    std::shared_ptr<Pickup> getItem() { return item; }

    void addItem(std::shared_ptr<Pickup> t_newItem);
    std::shared_ptr<Pickup> removeItem();

    void draw(float t_scale);
    void setColor(Color t_col) { color = t_col; }
    bool checkHover();


private:
    bool isDrawing = true;
    Texture2D bgTexture;

    std::shared_ptr<Pickup> item;
    Texture2D itemTexture;
    Rectangle itemSrcRect;
    Vector2 itemOrigin;
    Rectangle srcRect;
    Vector2 origin;
    Rectangle dstRect;
    bool empty = true;

    Vector2 position;
    static const Vector2 SIZE;
    static const int PADDING;

    Color color = WHITE;
};

#include "../include/Pickup.h"