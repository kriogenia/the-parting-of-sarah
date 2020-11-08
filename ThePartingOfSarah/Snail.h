#pragma once

#include "Enemy.h"

constexpr auto SNAIL_SPEED = 1;
constexpr auto SNAIL_HP = 5;
constexpr auto SNAIL_INVULNERATIBILITY_CD = 60;

class Snail : 
    public Enemy
{
public:
    Snail(float x, float y, Game* game);
    
private:
    void importAnimations() override;

    int timeToHide;
};

