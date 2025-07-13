#include "../include/Effect.h"


void defaultEffect()
{

}


Effect::Effect()
{
    // Add the default hit effect
    onHitEffects.push_back(defaultEffect);
}