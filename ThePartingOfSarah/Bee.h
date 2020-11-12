#pragma once

#include "Enemy.h"
#include "Room.h"
class Room;

constexpr auto BEE_SPEED = 1.5;
constexpr auto BEE_HP = 3;
constexpr auto BEE_SHOT_CADENCE = 55;
constexpr auto BEE_SHOT_FRAME = 5;
constexpr auto BEE_LOCK_DISTANCE = 150;
constexpr auto BEE_PROJECTILE_FILE = "res/sprites/bee/Bee_Projectile.png";

class Bee :
    public Enemy
{
public:
    Bee(float x, float y, Room* room, Game* game);
    ~Bee();

    void draw(int scrollX = 0, int scrollY = 0, float rotation = 0.0) override;
    void update() override;

    void shoot();

private:
    void setMovement() override;
    void setAction(bool endAction) override;
    void setOrientation() override;

    void importAnimations() override;

    Room* room;

    Animation* shootingAnimation;

    int shotTime;

};

