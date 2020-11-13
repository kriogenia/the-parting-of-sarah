#pragma once

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
	void updateCrosshair(int mouseX, int mouseY);
	void updateHealthDisplay(int currentHp, int maxHp);
	void updateMap(Room* room);

private:
	Crosshair* crosshair;
	HealthDisplay* health;
	MapDisplay* map;
	Game* game;
};

