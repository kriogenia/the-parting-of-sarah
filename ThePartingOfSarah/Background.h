#pragma once

#include "Actor.h"

class Background :
    public Actor {
public:
    Background(Game* game);
    Background(float x, float y, Game* game);
    /* Game cycle */
    void draw(int scrollX = 0, int scrollY = 0, float rotation = 0.0) override;
    void update();
private:
    /* Copy to cycle */
    Background* bgAux = nullptr;
};

