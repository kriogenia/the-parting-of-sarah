#include "CoinBar.h"

CoinBar::CoinBar(float x, float y, int startingHeight, Game* game) : 
	Actor("res/hud/coinbar_full.png", x, y, COIN_WIDTH, 10 * COIN_HEIGHT, game)
{
	this->currentHeight = startingHeight;
}

void CoinBar::draw(int scrollX, int scrollY, float rotation) {
	SDL_Rect source;
	source.x = 0;
	source.y = fileHeight - currentHeight;
	source.w = fileWidth;	
	source.h = currentHeight;		

	SDL_Rect destination;
	destination.x = x;
	destination.y = y + currentHeight;
	destination.w = width;
	destination.h = currentHeight;

	SDL_RenderCopyEx(game->renderer,
		texture, &source, &destination, rotation, NULL, SDL_FLIP_NONE);
}

void CoinBar::update(int currentCoins) {
	this->currentHeight = currentCoins * COIN_HEIGHT;
}