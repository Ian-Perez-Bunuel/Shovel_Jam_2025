#pragma once

#include "raylib.h"
#include "stdio.h"
#include <vector>
#include <memory>

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

    void addItem(std::shared_ptr<Pickup> t_newItem);
    void removeItem(std::shared_ptr<Pickup> t_newItem);

private:
    bool showing = false;

    std::vector<std::shared_ptr<Cell>> cells;

    static const int ROWS;
    static const int COLUMNS;
    static const int SIDE_PADDING;
    static const int TOP_PADDING;
    static const int SPACING;
};

#include "../include/Pickup.h"
#include "../include/Cell.h"