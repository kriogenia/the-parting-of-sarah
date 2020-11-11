#pragma once
#include "Actor.h"

/* Tile dimensions */
constexpr auto TILE_SIZE = 16;
constexpr auto HALF_TILE_SIZE = TILE_SIZE / 2;

/* Types of tiles */
enum eTileType {
	NO_TILE = ' ',
	FLOOR = '.',
	TOP_LEFT_WALL = '/',
	TOP_RIGHT_WALL = '\\',
	BOTTOM_LEFT_WALL = '{',
	BOTTOM_RIGHT_WALL = '}',
	TOP_WALL = 'T',
	LEFT_WALL = 'L',
	RIGHT_WALL = 'R',
	BOTTOM_WALL = 'B',
	HORIZONTAL_DOOR = '-',
	VERTICAL_DOOR = '|',
	ROCK = 'X',
	POND_TOP = 'P',
	POND_BASE = '~',
	BARREL = 'M',
	SPAWN = 'S'
};

class Tile :
    public Actor {
public:
    Tile(string filename, float x, float y, int width, int height, Game* game);
    Tile(string filename, float x, float y, int width, int height, int fileWidth, int fileHeight, Game* game);
};

