#include "EnemyFactory.h"

EnemyFactory* EnemyFactory::instance = 0;

EnemyFactory* EnemyFactory::getInstance() {
    if (instance == 0)
        instance = new EnemyFactory;
    return instance;
}

EnemyFactory::EnemyFactory() {}

Enemy* EnemyFactory::generateEnemy(float x, float y, Room* room, Game* game) {
    return new Snail(x, y, room->player, game);                       // Debug
    int typeOfEnemy = rand() % NUMBER_OF_ENEMY_TYPES;
    switch (typeOfEnemy) {
    case BEE:
        return new Bee(x, y, room, game);
    case BIRD:
        return new Bird(x, y, room->player, game);
    case PIG:
        return new Pig(x, y, room->player, game);
    case PLANT:
        return new Plant(x, y, room, game);
    case SNAIL:
        return new Snail(x, y, room->player, game);
    }

}