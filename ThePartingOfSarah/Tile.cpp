#include "Tile.h"

Tile::Tile(string filename, float x, float y, int width, int height, Game* game)
	: Actor(filename, x, y, width, height, game) 
{
	this->type = TILE;
}

Tile::Tile(string filename, float x, float y, int width, int height, int fileWidth, int fileHeight, Game* game)
	: Actor(filename, x, y, width, height, fileWidth, fileHeight, game) {
}