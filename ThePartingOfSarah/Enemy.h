#pragma once

#include "Character.h"

class Enemy :
    public Character
{
public:
    Enemy(string filename, float x, float y, int width, int height, Actor* player, Game* game);
    ~Enemy();

    void collisionedWith(Actor* actor) override;
    void damage(float damage = 1.0) override;

protected:
    void setMovement() override;
    void setAction(bool endAction) override;
    void setOrientation() override;

    Actor* player;

    Animation* dyingAnimation;
    map<eCharacterOrientation, Animation*> hitAnimations;
};

