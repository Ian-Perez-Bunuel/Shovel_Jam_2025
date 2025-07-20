#pragma once

#include "../include/GameObject.h"
#include "../include/ParticleSpawner.h"

class Obstacle : public GameObject
{
public:
    Obstacle(Vector2 t_pos, Color t_color, Texture2D& t_texture, bool t_interactable = true, float t_width = 100, float t_height = 100);
    void draw() override;
    void update() override;

    bool isInteractable() { return interactable; }
    void destroy();

    void grab();

    Rectangle getRect() { return rect; }
private:
    Texture2D& texture;
    Rectangle rect;

    bool interactable;
    
    float width;
    float height;

    bool grabbed = false;

    ParticleSpawner destructionParticles;

    Sound destoySound;
};