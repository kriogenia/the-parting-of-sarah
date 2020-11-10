#include "Spawner.h"

Spawner* Spawner::instance = 0;

Spawner* Spawner::getInstance() {
    if (instance == 0)
        instance = new Spawner();
    return instance;
}

Spawner::Spawner() {}

Enemy* Spawner::generateEnemy(float x, float y, Game* game) {
    return new Pig(x, y, NULL, game);
}