#include "../include/Cell.h"
#include "../include/Globals.h"

const Vector2 Cell::SIZE = {75, 75};
const int Cell::PADDING = 5;

Cell::Cell(Vector2 t_pos)
    :   position(t_pos)
{
    bgTexture = LoadTexture(PICKUPS_PATH"/background.png");
    srcRect = { 0, 0, (float)bgTexture.width, (float)bgTexture.height };
    origin = {bgTexture.width * 0.5f, bgTexture.height * 0.5f};
}

void Cell::addItem(std::shared_ptr<Pickup> t_newItem)
{
    empty = false;
    item = t_newItem;
    itemTexture = item->sprite->getTexture();
    itemSrcRect = { 0, 0, (float)itemTexture.width, (float)itemTexture.height };
    itemOrigin = {itemTexture.width * 0.5f, itemTexture.height * 0.5f};
}

std::shared_ptr<Pickup> Cell::removeItem()
{
    empty = true;

    std::shared_ptr<Pickup> itemRemoved = item;
    itemRemoved->drop();
    item = nullptr;

    return itemRemoved;
}

void Cell::draw(float t_scale)
{
    // Destination rectangle: position is the centre point, size is scaled
    dstRect = {
        position.x + (PADDING),
        position.y + (PADDING),
        (itemTexture.width  * INVENTORY_PIXEL_SCALE) * t_scale,
        (itemTexture.height * INVENTORY_PIXEL_SCALE) * t_scale
    };

    DrawTexturePro(bgTexture, srcRect, dstRect, origin, 0.0f, color);

    // Draw Item
    if (item != nullptr)
    {
        DrawTexturePro(itemTexture, itemSrcRect, dstRect, itemOrigin, 0.0f, WHITE);
    }
}

bool Cell::checkHover()
{
    if (item != nullptr)
    {
        if (CheckCollisionPointRec(GetMousePosition(), dstRect))
        {
            setColor(RED);
            return true;
        }
    }

    setColor(WHITE);
    return false;
}