#pragma once

#include "Enemy.h"

/* Attributes */
constexpr auto SNAIL_POINTS = 8;
constexpr auto SNAIL_HP = 5;
constexpr auto SNAIL_SPEED = 1;
constexpr auto SNAIL_INVULNERATIBILITY_CD = 90;

class Snail : 
    public Enemy
{
public:
    Snail(float x, float y, Environment* room, Game* game);
    ~Snail();
    /* Game cycle */
    void update() override;
    void damage(float damage = 1.0) override;
    
private:
    /* Character */
    void importAnimations() override;
    void setMovement() override;
    void setAction(bool endAction) override;
    void setAnimation() override;
    /* Extra action animations */
    Animation* hidingAnimation;
    /* Counter */
    int timeToHide;
};

