#pragma once

#include "raylib.h"
#include "stdio.h"
#include <vector>
#include <memory>

#include "../include/Effect.h"

class Pickup;
class Cell;

class Inventory
{
public:
    void init();

    void draw();
    void update();

    void open();
    void close();

    bool isShowing() { return showing; }

    std::vector<Effect> getEffects();

    bool addItem(std::shared_ptr<Pickup> t_newItem);
    std::shared_ptr<Pickup> removeItem();

private:
    bool showing = false;
    int itemsHeld = 0;
    bool full = false;

    const float CLOSED_SCALE = 0.5f;

    std::vector<std::shared_ptr<Cell>> cells;

    static const int ROWS;
    static const int COLUMNS;
    static const int SIDE_PADDING;
    static const int TOP_PADDING;
    static const int SPACING;
};

#include "../include/Pickup.h"
#include "../include/Cell.h"