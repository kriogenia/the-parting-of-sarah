#pragma once

#include "CoinBar.h"
#include "MappedTile.h"

class CoinDisplay
{
public:
	CoinDisplay(Game* game);

	void draw();
	void update(int currentCoins);

private:
	Tile* baseCoins;
	CoinBar* currentCoins;
	MappedTile* info;
	Game* game;
};