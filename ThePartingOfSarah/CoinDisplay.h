#pragma once

#include "CoinBar.h"
#include "MappedTile.h"

class CoinDisplay
{
public:
	CoinDisplay(Game* game);
	~CoinDisplay();
	/* Game cycle */
	void draw();
	void update(int currentCoins);

private:
	/* Components */
	Tile* baseCoins;
	CoinBar* currentCoins;
	MappedTile* info;
};