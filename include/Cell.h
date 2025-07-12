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

    void addItem(std::shared_ptr<Pickup> t_newItem);

    void draw();

private:
    std::shared_ptr<Pickup> item;
    bool empty = true;

    Vector2 position;
    static const Vector2 SIZE;
    static const int PADDING;
};

#include "../include/Pickup.h"