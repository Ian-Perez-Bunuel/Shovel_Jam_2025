#pragma once

#include "../include/GameObject.h"

class Player : public GameObject
{
public:
    void init(Vector2 t_pos, float t_radius);

    void draw() override;
    void update() override;

private:
    float speed = 2.0f;
};