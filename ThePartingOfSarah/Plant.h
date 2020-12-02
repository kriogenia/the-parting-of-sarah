#pragma once

#include "Enemy.h"
#include "Room.h"
class Room;

/* Attributes */
constexpr auto PLANT_POINTS = 10;
constexpr auto PLANT_HP = 6;
constexpr auto PLANT_SPEED = 0;
constexpr auto PLANT_SHOT_CADENCE = 75;
/* Files */
constexpr auto PLANT_SHOT_FRAME = 4;
constexpr auto PLANT_PROJECTILE_FILE = "res/sprites/plant/Plant_Projectile.png";

class Plant :
    public Enemy
{
public:
    Plant(float x, float y, Environment* room, Game* game);
    ~Plant();
    /* Game cycle */
    void update() override;
    /* Extra action */
    void shoot();

private:
    /* Character */
    void importAnimations() override;
    void setMovement() override {};
    void setAction(bool endAction) override;
    /* Extra action animations */
    map<eCharacterOrientation, Animation*> shootingAnimations;
    /* Counter */
    int shotTime;

};

