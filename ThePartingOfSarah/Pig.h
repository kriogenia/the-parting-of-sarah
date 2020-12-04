#pragma once

#include "Enemy.h"
class Enemy;

/* Attributes */
constexpr auto PIG_POINTS = 12;
constexpr auto PIG_HP = 8;
constexpr auto PIG_MOVING_SPEED = 2;
constexpr auto PIG_RUNNING_SPEED = 4;

class Pig :
    public Enemy
{
public:
    Pig(float x, float y, Environment* room, Game* game);
    ~Pig();

private:
    /* Character */
    void importAnimations() override;
    void setMovement() override;
    void setAction(bool endAction) override;
    void setAnimation() override;
    /* Extra action animations */
    map<eCharacterOrientation, Animation*> runningAnimations;
};

