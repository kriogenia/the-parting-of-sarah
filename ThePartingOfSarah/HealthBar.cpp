#include "HealthBar.h"

HealthBar::HealthBar(string filename, float x, float y, int startingWidth, int height, Game* game) :
	Actor(filename, x, y, startingWidth, height, game)
{
	this->currentWidth = startingWidth;
}

void HealthBar::draw(int scrollX, int scrollY, float rotation) {
	SDL_Rect source;
	source.x = 0;
	source.y = 0;
	source.w = currentWidth;	// width with the current max health
	source.h = fileHeight;		// texture.height;

	SDL_Rect destination;
	destination.x = x;
	destination.y = y;
	destination.w = currentWidth;
	destination.h = height;

	SDL_RenderCopyEx(game->renderer,
		texture, &source, &destination, rotation, NULL, SDL_FLIP_NONE);
}