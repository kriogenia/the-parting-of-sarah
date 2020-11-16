#pragma once

#include "Enemy.h"
class Enemy;

constexpr auto PIG_MOVING_SPEED = 2;
constexpr auto PIG_RUNNING_SPEED = 4;
constexpr auto PIG_HP = 5;

class Pig :
    public Enemy
{
public:
    Pig(float x, float y, Environment* room, Game* game);
    ~Pig();

private:
    void setMovement() override;
    void setAction(bool endAction) override;
    void setAnimation() override;

    void importAnimations() override;

    map<eCharacterOrientation, Animation*> runningAnimations;
};

