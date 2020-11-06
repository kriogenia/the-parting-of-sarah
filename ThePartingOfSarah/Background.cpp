#include "Background.h"

Background::Background(Game* game) :
	Actor("res/backgrounds/bg1.png", 0, 0, WIDTH, HEIGHT, 1920, 480, game) {
	this->vx = 1;
	bgAux = new Background(0, 0, game);
}

Background::Background(float x, float y, Game* game) :
	Actor("res/backgrounds/bg1.png", x, y, WIDTH, HEIGHT, 1920, 480, game) {
}

void Background::update() {
	x = x + vx;
	if (x >= fileWidth) {
		x = 0;
	}
}

void Background::draw(float scrollX, float scrollY) {
	int offset = ((x + WIDTH > fileWidth) ? fileWidth - x : 0);

	SDL_Rect source;
	source.x = x;
	source.y = 0;
	source.w = !offset ? WIDTH : offset;	// texture.width;
	source.h = HEIGHT;	// texture.height;

	SDL_Rect destination;
	destination.x = scrollX;
	destination.y = 0;
	destination.w = !offset ? WIDTH : offset;
	destination.h = HEIGHT;

	SDL_RenderCopyEx(game->renderer,
		texture, &source, &destination, 0, NULL, SDL_FLIP_NONE);

	if (bgAux != nullptr) {
		if (offset) {
			bgAux->draw(offset);
		}
	}
}