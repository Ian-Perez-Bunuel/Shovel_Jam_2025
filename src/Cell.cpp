#include "../include/Cell.h"

const Vector2 Cell::SIZE = {75, 75};

Cell::Cell(Vector2 t_pos)
    :   position(t_pos)
{
}

void Cell::addItem(std::shared_ptr<Pickup> t_newItem)
{

}

void Cell::draw()
{
    // Draw background
    DrawRectangleV(position, SIZE, WHITE);
}