#pragma once
#include "Actor.h"
class Crosshair :
    public Actor {
public:
    Crosshair(Game* game);

    void update(int mouseX, int mouseY);
};

