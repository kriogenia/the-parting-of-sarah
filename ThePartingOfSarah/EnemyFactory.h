#pragma once

#include "Bird.h"
#include "Pig.h"
#include "Snail.h"

#include "Room.h"
class Room;

constexpr auto NUMBER_OF_ENEMY_TYPES = 3;

enum TYPE_OF_ENEMY {
    BIRD,
    PIG,
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