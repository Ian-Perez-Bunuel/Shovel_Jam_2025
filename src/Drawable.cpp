#include "../include/Drawable.h"
#include "../include/Globals.h"

Drawable::Drawable(Vector2 &t_pos, bool& t_active)
    : position(t_pos), active(t_active)
{
}

void Drawable::setTexture(Texture2D& t_tex)
{
    texture = &t_tex;
    srcRect = { 0, 0, (float)texture->width, (float)texture->height };
}

void Drawable::draw()
{
    if (texture != nullptr && active)
    {
        // DrawTextureV(texture, position, WHITE);
        // Destination rectangle: position is the centre point, size is scaled
        Rectangle dstRect = {
            position.x,
            position.y,
            texture->width  * PIXEL_SCALE,
            texture->height * PIXEL_SCALE
        };

        // Origin for rotation/scaling: half of the destRect’s size
        Vector2 origin = {
            dstRect.width * 0.5f,
            dstRect.height * 0.5f
        };

        // Now draw with origin at the true centre
        DrawTexturePro(*texture, srcRect, dstRect, origin, 0.0f, WHITE);
    }
}
