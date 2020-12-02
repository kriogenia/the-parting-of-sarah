#pragma once

#include "Enemy.h"

/* Attributes */
constexpr auto BEE_POINTS = 10;
constexpr auto BEE_SPEED = 1.5;
constexpr auto BEE_HP = 3;
constexpr auto BEE_SHOT_CADENCE = 55;
constexpr auto BEE_SHOT_FRAME = 5;
constexpr auto BEE_LOCK_DISTANCE = 150;
/* Files */
constexpr auto BEE_PROJECTILE_FILE = "res/sprites/bee/Bee_Projectile.png";

class Bee :
    public Enemy
{
public:
    Bee(float x, float y, Environment* room, Game* game);
    ~Bee();
    /* Game cycle */
    void draw(int scrollX = 0, int scrollY = 0, float rotation = 0.0) override;
    void update() override;
    /* Extra action - TODO extract shooter interface */
    void shoot();

private:
    /* Character */
    void importAnimations() override;
    void setMovement() override;
    void setAction(bool endAction) override;
    void setOrientation() override {};
    /* Extra action animation */
    Animation* shootingAnimation;
    /* Counter */
    int shotTime;

};

