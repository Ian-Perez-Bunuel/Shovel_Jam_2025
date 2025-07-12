#include "../include/Cell.h"
#include "../include/Globals.h"

const Vector2 Cell::SIZE = {75, 75};
const int Cell::PADDING = 5;

Cell::Cell(Vector2 t_pos)
    :   position(t_pos)
{
}

void Cell::addItem(std::shared_ptr<Pickup> t_newItem)
{
    empty = false;
    item = t_newItem;
}

void Cell::draw()
{
    // Draw background
    DrawRectangleV(position, SIZE, WHITE);

    if (item != nullptr)
    {
        Texture2D texture = item->sprite->getTexture();
        Rectangle srcRect = { 0, 0, (float)texture.width, (float)texture.height };
        // DrawTextureV(texture, position, WHITE);
        // Destination rectangle: position is the centre point, size is scaled
        Rectangle dstRect = {
            position.x + PADDING,
            position.y + PADDING,
            texture.width  * INVENTORY_PIXEL_SCALE,
            texture.height * INVENTORY_PIXEL_SCALE
        };

        DrawTexturePro(texture, srcRect, dstRect, {0, 0}, 0.0f, WHITE);
    }
}