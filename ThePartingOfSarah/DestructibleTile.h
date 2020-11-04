#pragma once

#include "MappedTile.h"

class DestructibleTile :
    public MappedTile
{
public:
    DestructibleTile(string filename, int x, int y, int width, int hp, Game* game);

    void triggerImpact();
    bool isDestroyed();
private:
    int hp;
};

