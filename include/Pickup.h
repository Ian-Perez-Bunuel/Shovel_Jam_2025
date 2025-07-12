#pragma once

#include "raylib.h"
#include "../include/GameObject.h"

#include <vector>
#include <memory>

class Player;

class Pickup : public GameObject
{
public:
    void init(float t_radius, std::shared_ptr<Player> t_player);

    void spawn(Vector2 t_pos);
    virtual void draw() override;
    virtual void update() override;

    bool isActive() { return active; }

protected:
    virtual void onPickup();

    bool active = false;
    bool inInventory = false;
    std::shared_ptr<Player> player;

    static const float TRACKING_RADIUS;

private:

};

#include "../include/Player.h"