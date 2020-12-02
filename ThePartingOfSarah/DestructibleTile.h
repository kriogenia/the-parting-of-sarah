#pragma once

#include "MappedTile.h"

class DestructibleTile :
    public MappedTile
{
public:
    DestructibleTile(string filename, int x, int y, int width, int hp, Game* game);
    /* Actor */
    void collisionedWith(Actor* actor) override;
private:
    /* Attributes */
    int hp;
};

