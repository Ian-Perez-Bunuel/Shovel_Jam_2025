#include "../include/Effect.h"
#include "../include/Globals.h"

void defaultEffect()
{

}


Effect::Effect()
{
    // Add the default hit effect
    onHitEffects.push_back(defaultEffect);
}