#include "../include/GameObject.h"

void GameObject::init(Vector2 t_pos, Color t_color)
{
    position = t_pos;
    color = t_color;

    sprite = std::make_shared<Drawable>(position, active);
}