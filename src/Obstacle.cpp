#include "../include/Obstacle.h"

Obstacle::Obstacle(Vector2 t_pos, Color t_color, Texture2D &t_texture, bool t_interactable, float t_width, float t_height)
    : width(t_width), height(t_height), texture(t_texture), interactable(t_interactable)
{
    GameObject::init(t_pos, t_color);
    sprite->setTexture(texture);

    // build a Rect whose center is at centerPos
    rect = {
        position.x - width*0.5f,  // x = left edge
        position.y - height*0.5f, // y = top edge
        width,
        height
    };

    active = true;
}

void Obstacle::draw()
{
    if (active)
    {
        DrawRectangleRec(rect, color);
    }
}

void Obstacle::destroy()
{
    if (interactable)
    {
        active = false;
    }
}

void Obstacle::update()
{
    if (grabbed)
    {
        position = GetMousePosition();

        if (IsKeyDown(KEY_UP))
        {
            height += 5;
        }
        else if (IsKeyDown(KEY_DOWN))
        {
            height -= 5;
        }

        if (IsKeyDown(KEY_RIGHT))
        {
            width += 5;
        }
        else if (IsKeyDown(KEY_LEFT))
        {
            width -= 5;
        }

        rect = {
            position.x - width*0.5f,  // x = left edge
            position.y - height*0.5f, // y = top edge
            width,
            height
        };
    }
}

void Obstacle::grab()
{
    if (grabbed)
    {
        grabbed = false;
        color = YELLOW;
    }
    else
    {
        grabbed = true;
        color = PINK;
    }
}