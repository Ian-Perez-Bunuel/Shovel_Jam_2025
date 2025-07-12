#include "../include/Inventory.h"

const int Inventory::ROWS = 1;
const int Inventory::COLUMNS = 5;
const int Inventory::SIDE_PADDING = 150;
const int Inventory::TOP_PADDING = 50;
const int Inventory::SPACING = 15;


void Inventory::init()
{
    // Get grid
    for (int col = 0; col < COLUMNS; col++)
    {
        float xPos = SIDE_PADDING + col * (Cell::getSize().x + SPACING);

        for (int row = 0; row < ROWS; row++)
        {
            float yPos = TOP_PADDING + row * (Cell::getSize().y + SPACING);

            Vector2 pos = {xPos, yPos};
            cells.push_back(std::make_shared<Cell>(pos));
        }
    }
}

void Inventory::draw()
{
    if (showing)
    {
        for (std::shared_ptr<Cell>& cell : cells)
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

// If there is no space return false
bool Inventory::addItem(std::shared_ptr<Pickup> t_newItem)
{
    if (full)
    {
        return false;
    }
    else
    {
        for (std::shared_ptr<Cell>& cell : cells)
        {
            if (cell->isEmpty())
            {
                itemsHeld++;
                cell->addItem(t_newItem);
                break;
            }
        }

        if (itemsHeld >= ROWS*COLUMNS)
        {
            full = true;
        }

        return true;
    }
}

void Inventory::removeItem(std::shared_ptr<Pickup> t_newItem)
{
    itemsHeld--;
}