#pragma once

#include "Game.h"
class Game;

class Layer {
public:
	Layer(Game* game);
	/* Game cycle */
	virtual void init() = 0;
	virtual void processControls() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

	Game* game;
};
