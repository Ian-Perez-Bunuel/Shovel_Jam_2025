#include "../include/Renderer.h"
#include "../include/Globals.h"
#include <algorithm>    // for std::sort

void Renderer::addSprite(const std::shared_ptr<Drawable> t_newSprite)
{
    sprites.push_back(t_newSprite);
}

void Renderer::drawAll()
{
    // Make a little working copy
    auto sorted = sprites;  // vector<shared_ptr<Drawable>>

    std::sort(sorted.begin(), sorted.end(),
              [](auto const& a, auto const& b) {
                  return a->getYPos() < b->getYPos();
              });

    for (auto const& sprite : sorted)
    {
        sprite->draw();
    }
}

bool Renderer::checkIfUsed(int t_indexToCheck, const std::vector<int>& t_used)
{
    for (int i : t_used)
    {   
        if (i == t_indexToCheck)
        {
            return true;
        }
    }

    return false;
}