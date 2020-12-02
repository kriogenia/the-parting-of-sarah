#pragma once

#include "Enemy.h"

/* Attributes */
constexpr auto BIRD_POINTS = 11;
constexpr auto BIRD_HP = 3;
constexpr auto BIRD_MAX_SPEED = 7.0;
constexpr auto BIRD_FLOOR_SPEED = 2.5;
constexpr auto BIRD_MAX_RANGE = 480;

class Bird :
    public Enemy
{
public:
    Bird(float x, float y, Environment* room, Game* game);

private:
    /* Character */
    void importAnimations() override;
    void setMovement() override;

};
