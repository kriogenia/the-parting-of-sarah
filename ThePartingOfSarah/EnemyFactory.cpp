#include "EnemyFactory.h"

#include "Bee.h"
#include "Bird.h"
#include "Ghost.h"
#include "Pig.h"
#include "Plant.h"
#include "Snail.h"
#include "Stone.h"

#include "Barrelwood.h"
#include "Bore.h"
#include "Litost.h"
#include "Pera.h"

EnemyFactory* EnemyFactory::instance = 0;

EnemyFactory* EnemyFactory::getInstance() {
    if (instance == 0)
        instance = new EnemyFactory;
    return instance;
}

EnemyFactory::EnemyFactory() {}

// TODO change to map with prototype/clone
Enemy* EnemyFactory::generateEnemy(float x, float y, Environment* room, Game* game) {
    return new Ghost(x, y, room, game);                       // Debug
    int typeOfEnemy = rand() % NUMBER_OF_ENEMY_TYPES;
    switch (typeOfEnemy) {
    case BEE:
        return new Bee(x, y, room, game);
    case BIRD:
        return new Bird(x, y, room, game);
    case GHOST:
        return new Ghost(x, y, room, game);
    case PIG:
        return new Pig(x, y, room, game);
    case PLANT:
        return new Plant(x, y, room, game);
    case SNAIL:
        return new Snail(x, y, room, game);
    case STONE:
        return new Stone(x, y, room, game);
    }

}

Boss* EnemyFactory::generateBoss(float x, float y, Environment* room, Game* game) {
    int typeOfEnemy = rand() % NUMBER_OF_BOSSES;
    //typeOfEnemy = BORE;               // Debug
    switch (typeOfEnemy) {
    case BARRELWOOD:
        return new Barrelwood(x, y, room, game);
    case BORE:
        return new Bore(x, y, room, game);
    case LITOST:
        return new Litost(x, y, room, game);
    case PERA:
        return new Pera(x, y, room, game);
    }

}