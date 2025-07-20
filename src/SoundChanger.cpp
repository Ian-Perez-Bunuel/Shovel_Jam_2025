#include "../include/SoundChanger.h"
#include "../include/Globals.h"

void SoundChanger::init()
{
    volumes[1.0f] = LoadTexture(UI_PATH"/maxVol.png");
    volumes[0.75f] = LoadTexture(UI_PATH"/75Vol.png");
    volumes[0.5f] = LoadTexture(UI_PATH"/midVol.png");
    volumes[0.25f] = LoadTexture(UI_PATH"/minVol.png");
    volumes[0.0f] = LoadTexture(UI_PATH"/mutedVol.png");

    position = { SCREEN_WIDTH - 90, 25};

    rect = {
        position.x, 
        position.y,
        64,
        64
    };

    music = LoadMusicStream(SOUND_PATH"/music.mp3");
    SetMusicVolume(music, MASTER_VOLUME * 0.25f);
    PlayMusicStream(music);
}

void SoundChanger::checkForMouse()
{
    UpdateMusicStream(music);

    if (CheckCollisionPointRec(GetMousePosition(), rect))
    {
        if (IsMouseButtonReleased(0))
        {
            MASTER_VOLUME += 0.25;

            if (MASTER_VOLUME > 1.0f)
            {
                MASTER_VOLUME = 0.0f;
            }

            SetMusicVolume(music, MASTER_VOLUME * 0.25f);
        }
    }
}

void SoundChanger::draw()
{
    DrawTextureEx(volumes[MASTER_VOLUME], position, 0, 4, WHITE);
}