#pragma once

#include "Actor.h"
#include "Crosshair.h"

class Hud
{
public:
	Hud(Game* game);
	~Hud();

	void draw();
	void update(int mouseX, int mouseY);

private:
	Crosshair* crosshair;
	Game* game;
};

