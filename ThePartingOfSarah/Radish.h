#pragma once

#include "Enemy.h"

/* Attributes */
constexpr auto RADISH_POINTS = 15;
constexpr auto RADISH_HP = 15;
constexpr auto RADISH_SPEED = 2;

class Radish :
    public Enemy
{
public:
    Radish(float x, float y, Environment* room, Game* game);
    ~Radish();
private:
    /* Character */
    void importAnimations() override;
    void setAction(bool endedAction) override;
    /* Extra action animation */
    Animation* idleAnimation;
};

