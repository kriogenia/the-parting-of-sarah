#pragma once

#include "Tile.h"

class MappedTile : public Tile {
public:
	MappedTile(string filename, int x, int y, int width, int number, Game* game);
	MappedTile(string filename, int x, int y, int width, int height, int fileWidth, int fileHeight, int number, Game* game);

	void draw(float scrollX, float scrollY = 0) override;
protected:
	int position = 0;
};

