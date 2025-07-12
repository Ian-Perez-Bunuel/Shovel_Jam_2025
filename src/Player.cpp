#include "../include/Player.h"
#include <raymath.h>
#include "../include/Globals.h"

void Player::init(Vector2 t_pos, float t_radius)
{
    GameObject::init(t_pos, t_radius, BLUE);

    inventory.init();
}

void Player::draw()
{
    GameObject::draw();

    inventory.draw();
}

void Player::update()
{
    input();
    
    velocity = Vector2Scale(velocity, FRICTION);
    position = Vector2Add(position, velocity);

    inventory.update();
}

void Player::input()
{
    if (IsKeyDown(KEY_W))
    {
        velocity.y -= speed;
    }
    else if (IsKeyDown(KEY_S))
    {
        velocity.y += speed;
    }  

    if (IsKeyDown(KEY_A))
    {
        velocity.x -= speed;
    }
    else if (IsKeyDown(KEY_D))
    {
        velocity.x += speed;
    } 


    // Toggle inventory on and off
    if (IsKeyReleased(KEY_E))
    {
        if (inventory.isShowing())
        {
            inventory.close();
        }
        else
        {
            inventory.open();
        }
    }
}