#pragma once

#include "raylib.h"
#include "stdio.h"
#include <memory>
#include <string>

class Toggle
{
public:
    void init(Vector2 t_pos, std::string t_text);
    void draw();
    bool mouseCheck(int& t_credit, int t_amount);

    bool isOn() { return toggled; }
    void turnOff(int& t_credit, int t_amount = 0);
    void turnOn() { color = GREEN; toggled = true; }

private:
    bool toggled;
    std::string text;

    Vector2 position;

    Rectangle rect;
    float width;
    float height = 25;

    Color color;
};