#pragma once

#include "Game.h"
class Game;

/* interface */
class Layer {
public:
	Layer(Game* game);
	/* Game cycle */
	virtual void init() = 0;
	virtual void processControls();
	virtual void update() = 0;
	virtual void draw() = 0;
	/* Input control */
	virtual void keysToControl(SDL_Event event) = 0;
	virtual void mouseToControl(SDL_Event event) = 0;
	/* Controls */
	int mouseX = 0;
	int mouseY = 0;
	/* Score */
	int points = 0;

	Game* game;
};
