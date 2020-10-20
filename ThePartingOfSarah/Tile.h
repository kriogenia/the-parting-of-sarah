#pragma once
#include "Actor.h"

constexpr auto TILE_SIZE = 16;

class Tile :
    public Actor {
public:
    Tile(string filename, float x, float y, int width, int height, Game* game);
};

