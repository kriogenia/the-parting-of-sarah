#pragma once

#include "Enemy.h"

constexpr auto BIRD_MAX_SPEED = 7.0;
constexpr auto BIRD_STARTING_HP = 3;
constexpr auto BIRD_FLOOR_SPEED = 2.5;
constexpr auto BIRD_MAX_RANGE = 480;

class Bird :
    public Enemy
{
public:
    Bird(float x, float y, Actor* player, Game* game);

private:
    void setMovement() override;

    void importAnimations() override;
};
