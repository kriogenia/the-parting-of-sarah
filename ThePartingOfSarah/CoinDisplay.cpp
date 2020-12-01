#include "CoinDisplay.h"

CoinDisplay::CoinDisplay(Game* game)
{
	baseCoins = new Tile("res/hud/coinbar_empty.png", HEIGHT - COIN_WIDTH, WIDTH - 10 * COIN_HEIGHT,
		COIN_WIDTH, 10 * COIN_HEIGHT, game);
	currentCoins = new CoinBar(HEIGHT - COIN_WIDTH, WIDTH - 10 * COIN_HEIGHT, 0, game);
	info = new MappedTile("res/hud/coinbar_info.png", HEIGHT - 2*COIN_WIDTH, WIDTH - 14 * COIN_HEIGHT, 
		COIN_WIDTH, 10 * COIN_HEIGHT, 2 * COIN_WIDTH, 10 * COIN_HEIGHT, 0, game);
}

void CoinDisplay::draw() {
	baseCoins->draw();
	currentCoins->draw();
	info->draw();
}

void CoinDisplay::update(int coins) {
	currentCoins->update(coins);
	info->position = (coins >= 5) ? 1 : 0;
}