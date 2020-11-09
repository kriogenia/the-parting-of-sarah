#pragma once

#include "Character.h"

class Enemy :
    public Character
{
public:
    Enemy(string filename, float x, float y, int width, int height, Actor* player, Game* game);

    void collisionedWith(Actor* actor) override;

protected:
    void setMovement() override;
    void setOrientation() override;

    Actor* player;

    int speed;
};

