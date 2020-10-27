#pragma once

#include "Tile.h"

class FloorTile : public Tile {
public:
	FloorTile(int x, int y, int number, Game* game);

	void draw(float scrollX, float scrollY = 0) override;
private:
	int position = 0;
};

