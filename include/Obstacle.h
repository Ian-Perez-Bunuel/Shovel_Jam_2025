#pragma once

#include "../include/GameObject.h"

class Obstacle : public GameObject
{
public:
    Obstacle(Vector2 t_pos, Color t_color, Texture2D& t_texture, float t_width = 100, float t_height = 100);
    void draw() override;
    void update() override;

    Rectangle getRect() { return rect; }
private:
    Texture2D& texture;
    Rectangle rect;
    
    float width;
    float height;
};