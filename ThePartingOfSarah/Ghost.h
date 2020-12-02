#pragma once

#include "Enemy.h"

constexpr auto GHOST_POINTS = 9;
constexpr auto GHOST_HP = 4;
constexpr auto GHOST_SPEED = 1.5;
constexpr auto GHOST_HIDING_COOLDOWN = 120;         // 4s
constexpr auto GHOST_HIDING_DURATION = 60;          // 2s

class Ghost :
    public Enemy
{
public:
    Ghost(float x, float y, Environment* room, Game* game);
    /* Game cycle */
    void draw(int scrollX = 0, int scrollY = 0, float rotation = 0.0) override;
    void update() override;
private:
    /* Character */
    void importAnimations() override;
    void setAction(bool endedAction) override;

    map<eCharacterOrientation, Animation*> hideAnimations;

    int hidingCooldown;
    int hidingDuration;
};

