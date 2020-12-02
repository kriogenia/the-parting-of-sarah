#pragma once

#include "Enemy.h"
#include "Room.h"
class Room;

constexpr auto PLANT_POINTS = 10;
constexpr auto PLANT_HP = 6;
constexpr auto PLANT_SPEED = 0;
constexpr auto PLANT_SHOT_CADENCE = 75;
constexpr auto PLANT_SHOT_FRAME = 4;
constexpr auto PLANT_PROJECTILE_FILE = "res/sprites/plant/Plant_Projectile.png";

class Plant :
    public Enemy
{
public:
    Plant(float x, float y, Environment* room, Game* game);

    void update();

    void shoot();

private:
    void setMovement() override {};
    void setAction(bool endAction) override;

    void importAnimations() override;

    map<eCharacterOrientation, Animation*> shootingAnimations;

    int shotTime;

};

