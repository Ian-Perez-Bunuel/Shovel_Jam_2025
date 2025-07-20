#include "../include/Toggle.h"
#include "../include/Globals.h"

void Toggle::init(Vector2 t_pos, std::string t_text)
{
    text = t_text;
    width = text.size() * 15;

    color = RED;

    position = t_pos;

        rect = {
        position.x - 35,
        position.y,
        width + 35,
        height
    };

    onTexture = LoadTexture(UI_PATH"/on.png");
    offTexture = LoadTexture(UI_PATH"/off.png");

    addEffectSound = LoadSound(SOUND_PATH"/addEffect.wav");
}

void Toggle::draw()
{
    //DrawRectangleRec(rect, color);
    DrawText(text.c_str(), position.x, position.y + 5, 25, BLACK);

    Vector2 togglePos = {position.x - 35, position.y};
    if (toggled)
    {
        DrawTextureEx(onTexture, togglePos, 0, PIXEL_SCALE, WHITE);
    }
    else
    {
        DrawTextureEx(offTexture, togglePos, 0, PIXEL_SCALE, WHITE);
    }
}

// Toggles if enough credit to turn on
bool Toggle::mouseCheck(int& t_credit, int t_amount, bool& t_turnedOff)
{
    if (CheckCollisionPointRec(GetMousePosition(), rect))
    {
        if (!toggled)
        {
            if (t_credit >= t_amount)
            {
                toggled = true;
                t_credit -= t_amount;
                color = GREEN;
                t_turnedOff = false;

                float randChange = ((rand() % 4) - 2) / 10.0f;
                SetSoundVolume(addEffectSound, MASTER_VOLUME);
                SetSoundPitch(addEffectSound, 1 + randChange);
                PlaySound(addEffectSound);

                return true;
            }  
        }
        else
        {
            toggled = false;
            t_credit += t_amount;
            color = RED;
            t_turnedOff = true;
        }
    }

    return false;
}

void Toggle::turnOff(int &t_credit, int t_amount)
{
    if (toggled) // if on
    {
        toggled = false; 
        color = RED;

        t_credit += t_amount;
    }
}