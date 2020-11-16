#include "CoinBar.h"

CoinBar::CoinBar(float x, float y, int startingHeight, Game* game) : 
	Actor("res/hud/coinbar_full.png", x, y, COIN_WIDTH, 10 * COIN_HEIGHT, game)
{
	this->currentHeight = startingHeight * COIN_HEIGHT;
}

void CoinBar::draw(int scrollX, int scrollY, float rotation) {
	SDL_Rect source;
	source.x = 0;
	source.y = 0;
	source.w = fileWidth;	
	source.h = currentHeight;		

	SDL_Rect destination;
	destination.x = x - width / 2;
	destination.y = y + 5 * COIN_HEIGHT - currentHeight;
	destination.w = width;
	destination.h = currentHeight;

	SDL_RenderCopyEx(game->renderer,
		texture, &source, &destination, rotation, NULL, SDL_FLIP_NONE);
}

void CoinBar::update(int currentCoins) {
	this->currentHeight = currentCoins * COIN_HEIGHT;
}