#include "../include/Goal.h"
#include "../include/Globals.h"

void Goal::init(Vector2 t_pos)
{
    position = t_pos;
    texture = LoadTexture(SPRITE_PATH"/hole.png");

    source = { 0, 0, (float)texture.width, (float)texture.height };
    dest = {
        position.x,
        position.y,
        (float)texture.width * PIXEL_SCALE,
        (float)texture.height * PIXEL_SCALE
    };
    origin = { dest.width / 2.0f, dest.height / 2.0f };

    onEnterParticles.addColor(BLACK);
    onEnterParticles.setValues(position, 360, 0);

    levelCompleteSound = LoadSound(SOUND_PATH"/levelComplete.wav");
}

void Goal::draw()
{
    //DrawCircleV(position, radius, BLACK);

    DrawTexturePro(texture, source, dest, origin, 0, WHITE);
    onEnterParticles.draw();
}

bool Goal::checkForBall(std::shared_ptr<Projectile> &t_ball)
{
    onEnterParticles.update();

    if (CheckCollisionCircles(t_ball->getPos(), t_ball->getRadius(), position, radius))
    {
        onEnterParticles.spawn(1);

        float randChange = ((rand() % 4) - 2) / 10.0f;
        SetSoundVolume(levelCompleteSound, MASTER_VOLUME);
        SetSoundPitch(levelCompleteSound, 1 + randChange);
        PlaySound(levelCompleteSound);

        return true;
    }

    return false;
}
