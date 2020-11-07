#include "Actor.h"

Actor::Actor(string filename, float x, float y, int width, int height, Game* game)
	: Actor(filename, x, y, width, height, width, height, game) { }

Actor::Actor(string filename, float x, float y, int width, int height, 
	int fileWidth, int fileHeight, Game* game) :
	game(game),
	x(x),
	y(y),
	fileWidth(fileWidth),
	fileHeight(fileHeight),
	width(width),
	height(height)
{
	destructionFlag = false;
	texture = game->getTexture(filename);
}

Actor::~Actor() {
	SDL_DestroyTexture(texture);
}

void Actor::draw(float scrollX, float scrollY) {
	SDL_Rect source;
	source.x = 0;
	source.y = 0;
	source.w = fileWidth;	// texture.width;
	source.h = fileHeight;	// texture.height;

	SDL_Rect destination;
	destination.x = x - width / 2 - scrollX;
	destination.y = y - height / 2 - scrollY;
	destination.w = width;
	destination.h = height;

	SDL_RenderCopyEx(game->renderer,
		texture, &source, &destination, 0, NULL, SDL_FLIP_NONE);
}

bool Actor::isOverlap(Actor* actor) {
	bool overlap = false;
	if (actor->x - actor->width / 2 <= x + width / 2
		&& actor->x + actor->width / 2 >= x - width / 2
		&& actor->y + actor->height / 2 >= y - height / 2
		&& actor->y - actor->height / 2 <= y + height / 2) {
		overlap = true;
	}
	return overlap;
}

void Actor::collisionedWith(Actor* actor) {}