#include "Actor.h"

Actor::Actor(string filename, float x, float y, int width, int height, Game* game) : 
	game(game), 
	x(x), 
	y(y), 
	fileWidth(width), 
	fileHeight(height), 
	width(width), 
	height(height) {
	SDL_Surface* surface = IMG_Load(filename.c_str());
	texture = SDL_CreateTextureFromSurface(game->renderer, surface);
}

void Actor::draw() {
	SDL_Rect source;
	source.x = 0;
	source.y = 0;
	source.w = fileWidth;	// texture.width;
	source.h = fileHeight;	// texture.height;

	SDL_Rect destination;
	destination.x = x - width / 2;
	destination.y = y - height / 2;
	destination.w = width;
	destination.h = height;

	SDL_RenderCopyEx(game->renderer,
		texture, &source, &destination, 0, NULL, SDL_FLIP_NONE);
}
