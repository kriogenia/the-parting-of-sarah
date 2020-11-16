#pragma once

#include "CoinDisplay.h"
#include "Crosshair.h"
#include "HealthDisplay.h"
#include "MapDisplay.h"
#include "Player.h"
#include "Room.h"

class Hud
{
public:
	Hud(Game* game);
	~Hud();

	void draw();
	void updateCoins(int currentCoins);
	void updateCrosshair(int mouseX, int mouseY);
	void updateHealthDisplay(int currentHp, int maxHp);
	void updateMap(Room* room);

private:
	CoinDisplay* coins;
	Crosshair* crosshair;
	HealthDisplay* health;
	MapDisplay* map;
	Game* game;
};

