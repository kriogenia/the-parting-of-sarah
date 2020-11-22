#pragma once

#include "Boss.h"

constexpr auto LITOST_HP = 32;
constexpr auto LITOST_SPEED = 0;

class Litost :
    public Boss
{
public:
    Litost(float x, float y, Environment* room, Game* game);

private:
    void setOrientation() override;

    void importAnimations() override;
};

