#pragma once

#include "Actor.h"
#include "Animation.h"

enum eCharacterAction {
    IDLE,
    MOVING,
    SHOOTING,
    DYING
};

class Character :
    public Actor
{
public:
    Character(string filename, float x, float y, int width, int height, Game* game);
    Character(string filename, float x, float y, int width, int height, int fileWidth, int fileHeight, Game* game);

    virtual void update();
    void draw(int scrollX = 0, int scrollY = 0) override;

    // void damage();

protected:
    Animation* animation;

    int hp;
};

