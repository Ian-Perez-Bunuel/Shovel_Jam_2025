#include "../include/GameObject.h"

void GameObject::init(Vector2 t_pos, float t_radius, Color t_color)
{
    position = t_pos;
    radius = t_radius;
    color = t_color;

    sprite = std::make_shared<Drawable>(position, active);
    // sprite->setTexture(texture);
}

void GameObject::draw()
{   
    // Hitbox
    DrawCircleV(position, radius, color);
    // Sprite - Only drawn when one is set
    // sprite->draw();
}