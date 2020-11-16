#pragma once

#include "Bee.h"
#include "Bird.h"
#include "Pig.h"
#include "Plant.h"
#include "Snail.h"

constexpr auto NUMBER_OF_ENEMY_TYPES = 4;

enum TYPE_OF_ENEMY {
    BEE,
    BIRD,
    PIG,
    PLANT,
    SNAIL
};

/* Singleton */
class EnemyFactory
{
public:
    static EnemyFactory* getInstance();
    /* Enemy generator */
    Enemy* generateEnemy(float x, float y, Environment* room, Game* game);

private:
    static EnemyFactory* instance;

    EnemyFactory();
};