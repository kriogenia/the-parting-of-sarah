#pragma once

#include "Actor.h"

class Crosshair :
    public Actor {
public:
    Crosshair(Game* game);
    /* Game cycle */
    void update(int mouseX, int mouseY);
};

