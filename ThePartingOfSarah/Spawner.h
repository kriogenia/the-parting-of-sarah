#pragma once

#include "Pig.h"

class Spawner
{
public:
    static Spawner* getInstance();

    Enemy* generateEnemy(float x, float y, Game* game);
private:
    static Spawner* instance;
    Spawner();
};