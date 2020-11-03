#pragma once

#include "Actor.h"

class Background :
    public Actor {
public:
    Background(Game* game);
    Background(float x, float y, Game* game);

    void draw(float scrollX = 0, float scrollY = 0) override;
    void update();
private:
    Background* bgAux = nullptr;
};

