#pragma once

#include "Boss.h"

constexpr auto NUMBER_OF_ENEMY_TYPES = 8;
constexpr auto NUMBER_OF_BOSSES = 4;

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