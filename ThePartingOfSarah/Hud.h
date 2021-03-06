#pragma once

#include "CoinDisplay.h"
#include "Crosshair.h"
#include "BossHealthDisplay.h"
#include "MapDisplay.h"
#include "PauseDisplay.h"
#include "Player.h"
#include "Room.h"
#include "TextDisplay.h"

class Hud
{
public:
	Hud(Game* game);
	~Hud();
	/* Game cycle*/
	void draw(bool isPaused);
	void updateBossHealthDisplay(int currentHp, int maxHp);
	void updateCoins(int currentCoins);
	void updateCrosshair(int mouseX, int mouseY);
	void updateHealthDisplay(int currentHp, int maxHp);
	void updateMap(Room* room);
	void updateStats(Player* player);
	void updateText(string message, string submessage = " ");
	/* Reset */
	void resetMap();

private:
	/* HUD modules */
	BossHealthDisplay* boss;
	CoinDisplay* coins;
	Crosshair* crosshair;
	HealthDisplay* health;
	MapDisplay* map;
	PauseDisplay* pause;
	TextDisplay* text;

	Game* game;
};

