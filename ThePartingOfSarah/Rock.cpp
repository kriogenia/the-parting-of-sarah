#include "Rock.h"

Rock::Rock(float x, float y, Game* game) :
	Tile("res/tiles/rock.png", x, y, 16, 16, game) {}