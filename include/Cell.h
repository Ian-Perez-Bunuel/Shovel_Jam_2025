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

    void addItem(std::shared_ptr<Pickup> t_newItem);

    void draw();

private:
    std::shared_ptr<Pickup> item;

    Vector2 position;
    static const Vector2 SIZE;
};

#include "../include/Pickup.h"