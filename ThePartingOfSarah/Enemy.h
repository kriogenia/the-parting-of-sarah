#pragma once

#include "Character.h"
#include "Environment.h"

constexpr auto COIN_RARITY = 4;

class Enemy :
    public Character
{
public:
    Enemy(string filename, float x, float y, int width, int height, Environment* room, Game* game);
    ~Enemy();

    void collisionedWith(Actor* actor) override;
    void damage(float damage = 1.0) override;

protected:
    void setMovement() override;
    void setAction(bool endAction) override;
    void setOrientation() override;

    virtual void death();
    void hit();

    Environment* room;

    Animation* dyingAnimation;
    map<eCharacterOrientation, Animation*> hitAnimations;
};

