#pragma once

#include "../include/GameObject.h"
#include "../include/Inventory.h"


class Player : public GameObject
{
public:
    void init(Vector2 t_pos, float t_radius);

    void draw() override;
    void update() override;

    Inventory inventory;

private:
    void input();

    float speed = 2.0f;
};