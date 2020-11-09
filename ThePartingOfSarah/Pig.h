#pragma once

#include "Enemy.h"

constexpr auto PIG_MOVING_SPEED = 2;
constexpr auto PIG_RUNNING_SPEED = 4;
constexpr auto PIG_STARTING_HP = 10;

class Pig :
    public Enemy
{
public:
    Pig(float x, float y, Actor* player, Game* game);
    ~Pig();

private:
    void setMovement() override;
    void setAction(bool endAction) override;
    void setAnimation() override;

    void importAnimations() override;

    map<eCharacterOrientation, Animation*> runningAnimations;
};

