#pragma once

#include "Game.h"
#include "Player.h"
#include "Text.h"

class PauseDisplay
{
public:
	PauseDisplay(Game* game);
	~PauseDisplay();
	/* Game cycle */
	void draw();
	void update(Player* player);
private:
	Game* game;
	/* Background */
	Actor* bg;
	/* Texts */
	Text* hp;
	Text* attack;
	Text* speed;
	Text* cadence;
	Text* projectile;
};

