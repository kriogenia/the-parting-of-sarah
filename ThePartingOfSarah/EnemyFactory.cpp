#include "EnemyFactory.h"

EnemyFactory* EnemyFactory::instance = 0;

EnemyFactory* EnemyFactory::getInstance() {
    if (instance == 0)
        instance = new EnemyFactory;
    return instance;
}

EnemyFactory::EnemyFactory() {}

Enemy* EnemyFactory::generateEnemy(float x, float y, Environment* room, Game* game) {
    return new Bee(x, y, room, game);                       // Debug
    int typeOfEnemy = rand() % NUMBER_OF_ENEMY_TYPES;
    switch (typeOfEnemy) {
    case BEE:
        return new Bee(x, y, room, game);
    case BIRD:
        return new Bird(x, y, room, game);
    case PIG:
        return new Pig(x, y, room, game);
    case PLANT:
        return new Plant(x, y, room, game);
    case SNAIL:
        return new Snail(x, y, room, game);
    }

}

Boss* EnemyFactory::generateBoss(float x, float y, Environment* room, Game* game) {
    int typeOfEnemy = rand() % NUMBER_OF_BOSSES;
    switch (typeOfEnemy) {
    case LITOST:
        return new Litost(x, y, room, game);
    }
}