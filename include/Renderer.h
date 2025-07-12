#include "../include/Drawable.h"
#include <vector>
#include <memory>

class Renderer
{
public:
    void addSprite(const std::shared_ptr<Drawable> t_newSprite);

    void drawAll();
private:
    std::vector<std::shared_ptr<Drawable>> sprites;


    bool checkIfUsed(int t_indexToCheck, const std::vector<int>& t_used);
};