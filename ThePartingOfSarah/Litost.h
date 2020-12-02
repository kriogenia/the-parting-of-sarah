#pragma once

#include "Boss.h"

/* Attributes */
constexpr auto LITOST_HP = 32;
constexpr auto LITOST_SPEED = 0;
constexpr auto LITOST_SHOT_SPREAD = 30;
/* Files */
constexpr auto LITOST_FANG_PROJECTILE_FILE = "res/sprites/litost/Litost_Fang_Projectile.png";
constexpr auto LITOST_FISH_PROJECTILE_FILE = "res/sprites/litost/Litost_Fish_Projectile.png";

enum eLitostMoveset {
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
    /* Character */
    void damage(float damage = 1.0) override;

private:
    /* Character */
    void importAnimations() override;
    void setOrientation() override {}
    /* Boss */
    void doAction() override;
    /* Moveset */
    void shieldUp();
    void shootCone();
    void shootFromWalls();
    /* Action animations */
    Animation* shieldAnimation;
    Animation* shootConeAnimation;
    Animation* shootFromWallAnimation;
};

