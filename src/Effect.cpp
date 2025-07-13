#include "../include/Effect.h"
#include "../include/Globals.h"
#include "stdio.h"

void defaultEffect()
{
    printf("\nDEFAULT EFFECT\n\n");
}


Effect::Effect()
{
    // Add the default hit effect
    onHitEffects.push_back(defaultEffect);
}