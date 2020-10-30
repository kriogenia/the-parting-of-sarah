#pragma once
#include "Tile.h"
class Water :
    public Tile
{
    Water(string filename, float x, float y, int width, int height, Game* game);
};

