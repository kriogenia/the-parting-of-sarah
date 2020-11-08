#pragma once

#include "Character.h"

class Enemy :
    public Character
{
public:
    Enemy(string filename, float x, float y, int width, int height, Game* game);

    void collisionedWith(Actor* actor) override;
};

