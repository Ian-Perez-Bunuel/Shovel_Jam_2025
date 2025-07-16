#include "../include/Obstacle.h"

Obstacle::Obstacle(Vector2 t_pos, Color t_color, Texture2D &t_texture, float t_width, float t_height)
    : width(t_width), height(t_height), texture(t_texture)
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
}

void Obstacle::draw()
{
    DrawRectangleRec(rect, color);
}

void Obstacle::update()
{
}