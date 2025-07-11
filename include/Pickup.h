#pragma once

#include "raylib.h"
#include "../include/GameObject.h"
#include "../include/Player.h"

#include <vector>
#include <memory>

class Pickup : public GameObject
{
public:
    void init(float t_radius, std::shared_ptr<Player> t_player);

    void spawn(Vector2 t_pos);
    void draw() override;
    void update() override;

    bool isActive() { return active; }

protected:
    bool active = false;
    std::shared_ptr<Player> player;

    static const float TRACKING_RADIUS;

private:

};