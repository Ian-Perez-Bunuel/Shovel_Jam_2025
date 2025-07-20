#include "../include/Button.h"
#include "../include/Globals.h"

const float Button::MAX_SCALE = 1.1f;
const float Button::SCALE_PER_FRAME = 0.05f;

void Button::init(Vector2 t_pos, float t_width, float t_height, std::string t_text, Texture2D t_texture)
{
    texture = t_texture;
    srcRect = { 0, 0, (float)texture.width, (float)texture.height };

    position = t_pos;
    text = t_text;

    baseWidth = t_width;
    baseHeight = t_height;
    rect = {
        position.x - baseWidth  / 2.0f,
        position.y - baseHeight / 2.0f,
        t_width,
        t_height
    };

    textWidth = MeasureText(text.c_str(), fontSize);
    textHeight = fontSize;
}

void Button::draw()
{
    // float scaledWidth = baseWidth * scale;
    // float scaledHeight = baseHeight * scale;

    // rect = {
    //     position.x - scaledWidth / 2.0f,
    //     position.y - scaledHeight / 2.0f,
    //     scaledWidth,
    //     scaledHeight
    // };
    // DrawRectangleRec(rect, YELLOW);

    dstRect = {
            position.x,
         position.y,
        ((float)texture.width  * PIXEL_SCALE) * scale,
        ((float)texture.height * PIXEL_SCALE) * scale
    };

        // Origin for rotation/scaling: half of the destRect’s size
    origin = {
        dstRect.width * 0.5f,
        dstRect.height * 0.5f
    };

    // Now draw with origin at the true centre
    DrawTexturePro(texture, srcRect, dstRect, origin, 0.0f, WHITE);

    float textX = rect.x + (rect.width  - textWidth)  / 2.0f;
    float textY = rect.y + (rect.height - textHeight) / 2.0f;

    DrawText(text.c_str(), (int)textX, (int)textY, fontSize, BLACK);
}

bool Button::checkForMouse()
{
    if (CheckCollisionPointRec(GetMousePosition(), rect))
    {
        if (scale < MAX_SCALE)
        {
            scale += SCALE_PER_FRAME;
        }

        hovering = true;

        return true;
    }
    else
    {
        if (scale > 1.0f)
        {
            scale -= SCALE_PER_FRAME * 2;
        }

        hovering = false;
    }

    return false;
}