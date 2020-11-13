#pragma once

#include "Crosshair.h"
#include "HealthDisplay.h"
#include "Player.h"

class Hud
{
public:
	Hud(Game* game);
	~Hud();

	void draw();
	void updateCrosshair(int mouseX, int mouseY);
	void updateHealthDisplay(int currentHp, int maxHp);

private:
	Crosshair* crosshair;
	HealthDisplay* health;
	Game* game;
};

