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

void Drawable::setAnimations(int t_rowNum, int t_colNum, int t_frameWidth, int t_frameHeight)
{
    animated = true;

    rowNum = t_rowNum;
    colNum = t_colNum;
    frameWidth = t_frameWidth;
    frameHeight = t_frameHeight;
}

void Drawable::draw()
{
    if (texture != nullptr && active)
    {
        if (animated)
        {
            animate();

            dstRect = {
                position.x,
                position.y,
                (float)frameWidth  * PIXEL_SCALE,
                (float)frameHeight * PIXEL_SCALE
            };

            srcRect = {
                (float)currentFrame * frameWidth,
                0,
                (float)frameWidth,
                (float)frameHeight
            };
        }
        else
        {
            // Destination rectangle: position is the centre point, size is scaled
            dstRect = {
                position.x,
                position.y,
                (float)texture->width  * PIXEL_SCALE,
                (float)texture->height * PIXEL_SCALE
            };
        }

        // Origin for rotation/scaling: half of the destRect’s size
        origin = {
            dstRect.width * 0.5f,
            dstRect.height * 0.5f
        };

        // Now draw with origin at the true centre
        DrawTexturePro(*texture, srcRect, dstRect, origin, 0.0f, WHITE);
    }
}

void Drawable::animate()
{
    frameTimer += GetFrameTime();
    if (frameTimer >= ANIMATION_SPEED)
    {
        frameTimer -= ANIMATION_SPEED;
        currentFrame = (currentFrame + 1) % colNum;
    }
}
