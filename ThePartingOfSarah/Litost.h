#pragma once

#include "Boss.h"

constexpr auto LITOST_HP = 32;
constexpr auto LITOST_SPEED = 0;
constexpr auto LITOST_SHOT_SPREAD = 30;
constexpr auto LITOST_FANG_PROJECTILE_FILE = "res/sprites/litost/Litost_Fang_Projectile.png";
constexpr auto LITOST_FISH_PROJECTILE_FILE = "res/sprites/litost/Litost_Fish_Projectile.png";

enum eLitostActions {
    SHIELD_UP,
    SHOOT_FROM_WALLS,
    SHOOT_CONE
};

class Litost :
    public Boss
{
public:
    Litost(float x, float y, Environment* room, Game* game);
    ~Litost();

    void damage(float damage = 1.0) override;

private:
    void setOrientation() override {}

    void importAnimations() override;

    void doAction() override;
    /* Pool of actions of the boss */
    void shieldUp();
    void shootCone();
    void shootFromWalls();
    /* Action animations */
    Animation* shieldAnimation;
    Animation* shootConeAnimation;
    Animation* shootFromWallAnimation;
};

