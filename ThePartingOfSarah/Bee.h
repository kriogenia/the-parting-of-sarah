#pragma once

#include "Enemy.h"
#include "Room.h"
class Room;

constexpr auto BEE_SPEED = 2.5;
constexpr auto BEE_HP = 3;
constexpr auto BEE_LOCK_DISTANCE = 480;

class Bee :
    public Enemy
{
public:
    Bee(float x, float y, Room* room, Game* game);
    ~Bee();

    void draw(int scrollX = 0, int scrollY = 0, float rotation = 0.0) override;

private:
    void setOrientation();

    void importAnimations() override;

    Room* room;

    Animation* shootingAnimation;
};

