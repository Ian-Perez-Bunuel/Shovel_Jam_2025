#pragma once

#include "raylib.h"
#include "../include/GameObject.h"

#include <vector>
#include <memory>

class Player;
class Cell;

class Pickup : public GameObject, public std::enable_shared_from_this<Pickup> 
{
    friend Cell;
public:
    void init(float t_radius, std::shared_ptr<Player> t_player);

    void spawn(Vector2 t_pos);
    virtual void update() override;
    virtual void draw() override;

    bool isActive() { return active; }

protected:
    bool checkCollision();
    virtual void onPickup();

    Texture2D texture;

    bool inInventory = false;
    std::shared_ptr<Player> player;

    static const float PICKUP_RADIUS;

private:

};

#include "../include/Player.h"
#include "../include/Cell.h"