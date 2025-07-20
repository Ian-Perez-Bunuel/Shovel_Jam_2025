#pragma once

#include "raylib.h"
#include "stdio.h"
#include <map>

class SoundChanger
{
public: 
    void init();
    ~SoundChanger() { UnloadMusicStream(music); }

    void checkForMouse();
    void draw();

private:
    Texture2D maxVol;
    Texture2D midVol;
    Texture2D minVol;
    Texture2D mutedVol;

    std::map<float, Texture2D> volumes;

    Vector2 position;
    Rectangle rect;

    Music music;
};