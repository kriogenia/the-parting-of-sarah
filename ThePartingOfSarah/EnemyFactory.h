#pragma once

#include "Bee.h"
#include "Bird.h"
#include "Pig.h"
#include "Plant.h"
#include "Snail.h"

#include "Room.h"
class Room;

constexpr auto NUMBER_OF_ENEMY_TYPES = 4;

enum TYPE_OF_ENEMY {
    BEE,
    BIRD,
    PIG,
    PLANT,
    SNAIL
};

class EnemyFactory
{
private:
    /* Here will be the instance stored. */
    static EnemyFactory* instance;
    /* Private constructor to prevent instancing. */
    EnemyFactory();

public:
    /* Static access method. */
    static EnemyFactory* getInstance();
    /* Enemy generator */
    Enemy* generateEnemy(float x, float y, Room* room, Game* game);

};