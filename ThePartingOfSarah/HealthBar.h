#pragma once

#include "Actor.h"

class HealthBar :
    public Actor
{
public:
    HealthBar(string filename, float x, float y, int startingWidth, int height, Game* game);

    void draw(int scrollX = 0, int scrollY = 0, float rotation = 0.0) override;

    int currentWidth;

};