#include "MappedTile.h"

MappedTile::MappedTile(string filename, int x, int y, int width, int pos, Game* game) :
	Tile(filename, x, y, 16, 16, width, 16, game) {
	this->position = pos;
}

void MappedTile::draw(float scrollX, float scrollY) {
	SDL_Rect source;
	source.x = TILE_SIZE * position;
	source.y = 0;
	source.w = width;	// texture.width;
	source.h = height;	// texture.height;

	SDL_Rect destination;
	destination.x = x - width / 2 - scrollX;
	destination.y = y - height / 2 - scrollY;
	destination.w = width;
	destination.h = height;

	SDL_RenderCopyEx(game->renderer,
		texture, &source, &destination, 0, NULL, SDL_FLIP_NONE);
}