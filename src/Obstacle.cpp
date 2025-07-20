#include "../include/Obstacle.h"
#include "../include/Globals.h"

Obstacle::Obstacle(Vector2 t_pos, Color t_color, Texture2D &t_texture, bool t_interactable, float t_width, float t_height)
    : width(t_width), height(t_height), texture(t_texture), interactable(t_interactable)
{
    GameObject::init(t_pos, t_color);
    SetTextureWrap(texture, TEXTURE_WRAP_REPEAT);
    sprite->setTexture(texture);

    // build a Rect whose center is at centerPos
    rect = {
        position.x - width*0.5f,  // x = left edge
        position.y - height*0.5f, // y = top edge
        width,
        height
    };

    active = true;

    destructionParticles.addColor(WALL_COLOR);

    destoySound = LoadSound(SOUND_PATH"/explosion.wav");
}

void Obstacle::draw()
{
    destructionParticles.draw();

    if (!active) return;

    float scaledTileWidth = texture.width * PIXEL_SCALE;
    float scaledTileHeight = texture.height * PIXEL_SCALE;

    // How many times the texture fits in the obstacle
    float tileFactorX = width / scaledTileWidth;
    float tileFactorY = height / scaledTileHeight;

    // Repeat the texture by enlarging the source rectangle
    Rectangle source = {
        0, 0,
        texture.width * tileFactorX,
        texture.height * tileFactorY
    };

    Rectangle dest = rect; // draw directly to the obstacle rect
    Vector2 origin = { 0, 0 };

    DrawTexturePro(texture, source, dest, origin, 0.0f, WHITE);
}


void Obstacle::destroy()
{
    if (interactable)
    {
        destructionParticles.setValues(position, 360, 0);
        destructionParticles.spawn(35);

        float randChange = ((rand() % 4) - 2) / 10.0f;
        SetSoundVolume(destoySound, MASTER_VOLUME);
        SetSoundPitch(destoySound, 1 + randChange);
        PlaySound(destoySound);

        active = false;
    }
}

void Obstacle::update()
{
    if (grabbed)
    {
        position = GetMousePosition();

        if (IsKeyDown(KEY_UP))
        {
            height += 32;
        }
        else if (IsKeyDown(KEY_DOWN))
        {
            height -= 32;
            if (height < 32)
            {
                height = 32;
            }
        }

        if (IsKeyDown(KEY_RIGHT))
        {
            width += 32;
        }
        else if (IsKeyDown(KEY_LEFT))
        {
            width -= 32;

            if (width < 32)
            {
                width = 32;
            }
        }

        rect = {
            position.x - width*0.5f,  // x = left edge
            position.y - height*0.5f, // y = top edge
            width,
            height
        };
    }

    destructionParticles.update();
}

void Obstacle::grab()
{
    if (grabbed)
    {
        grabbed = false;
        //color = WHITE;
    }
    else
    {
        grabbed = true;
        //color = GRAY;
    }
}