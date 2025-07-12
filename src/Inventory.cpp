#include "../include/Inventory.h"

const int Inventory::ROWS = 5;
const int Inventory::COLUMNS = 5;
const int Inventory::SIDE_PADDING = 50;
const int Inventory::TOP_PADDING = 200;
const int Inventory::SPACING = 15;


void Inventory::init()
{
    // Get grid
    for (int row = 0; row < ROWS; row++)
    {
        float xPos = SIDE_PADDING + row * (Cell::getSize().x + SPACING);

        for (int col = 0; col < COLUMNS; col++)
        {
            float yPos = TOP_PADDING + col * (Cell::getSize().y + SPACING);

            Vector2 pos = {xPos, yPos};
            cells.push_back(std::make_shared<Cell>(pos));
        }
    }
}

void Inventory::draw()
{
    if (showing)
    {
        for (std::shared_ptr<Cell> cell : cells)
        {
            cell->draw();
        }
    }
}

void Inventory::update()
{
    if (showing)
    {

    }
}

void Inventory::open()
{
    showing = true;
}

void Inventory::close()
{
    showing = false;
}

void Inventory::addItem(std::shared_ptr<Pickup> t_newItem)
{
    for (std::shared_ptr<Cell> cell : cells)
    {
        cell->addItem(t_newItem);
    }
}

void Inventory::removeItem(std::shared_ptr<Pickup> t_newItem)
{
}