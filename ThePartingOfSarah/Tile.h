#pragma once
#include "Actor.h"

constexpr auto TILE_SIZE = 16;
constexpr auto HALF_TILE_SIZE = TILE_SIZE / 2;

class Tile :
    public Actor {
public:
    Tile(string filename, float x, float y, int width, int height, Game* game);
    Tile(string filename, float x, float y, int width, int height, int fileWidth, int fileHeight, Game* game);
};

