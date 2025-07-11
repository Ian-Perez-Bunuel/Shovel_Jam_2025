#pragma once

#include "raylib.h"
#include "../include/GameObject.h"

#include <vector>
#include <memory>

class Player;
class Cell;

class Pickup : public GameObject
{
    friend Cell;
public:
    void init(float t_radius, std::shared_ptr<Player> t_player);

    void spawn(Vector2 t_pos);
    virtual void update() override;
    virtual void draw() override;

    virtual void pickup();
    static const float PICKUP_RADIUS;

protected:

    bool inInventory = false;
    std::shared_ptr<Player> player;

private:

};

#include "../include/Player.h"
#include "../include/Cell.h"