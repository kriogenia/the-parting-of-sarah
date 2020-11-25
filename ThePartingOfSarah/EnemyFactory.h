#pragma once

#include "Bee.h"
#include "Bird.h"
#include "Pig.h"
#include "Plant.h"
#include "Snail.h"

#include "Litost.h"

constexpr auto NUMBER_OF_ENEMY_TYPES = 5;
constexpr auto NUMBER_OF_BOSSES = 1;

/* Singleton */
class EnemyFactory
{
public:
    static EnemyFactory* getInstance();
    /* Enemy generator */
    Enemy* generateEnemy(float x, float y, Environment* room, Game* game);
    /* Boss generator */
    Boss* generateBoss(float x, float y, Environment* room, Game* game);

private:
    static EnemyFactory* instance;

    EnemyFactory();
};