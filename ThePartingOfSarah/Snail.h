#pragma once

#include "Enemy.h"

constexpr auto SNAIL_SPEED = 1;
constexpr auto SNAIL_HP = 5;
constexpr auto SNAIL_INVULNERATIBILITY_CD = 90;

class Snail : 
    public Enemy
{
public:
    Snail(float x, float y, Actor* player, Game* game);
    ~Snail();

    void update() override;
    void damage() override;
    
private:
    void setMovement() override;
    void setAction(bool endAction) override;
    void setAnimation() override;

    void importAnimations() override;

    Animation* hidingAnimation;

    int timeToHide;
};

