#include "../include/Toggle.h"

void Toggle::init(Vector2 t_pos, std::string t_text)
{
    text = t_text;
    width = text.size() * 15;

    color = RED;

    position = t_pos;

        rect = {
        position.x,
        position.y,
        width,
        height
    };
}

void Toggle::draw()
{
    DrawRectangleRec(rect, color);
    DrawText(text.c_str(), position.x, position.y, 25, BLACK);
}

// Toggles if enough credit to turn on
bool Toggle::mouseCheck(int& t_credit, int t_amount)
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

                return true;
            }  
        }
        else
        {
            toggled = false;
            t_credit += t_amount;
            color = RED;
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