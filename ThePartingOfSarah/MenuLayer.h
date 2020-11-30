#pragma once

#include "Actor.h"
#include "Layer.h"
#include "Crosshair.h"

class MenuLayer :
    public Layer
{
public:
	MenuLayer(Game* game);
	/* Game cycle */
	void init() override;
	void draw() override;
	void update() override;
	/* Controls */
	void keysToControl(SDL_Event event) override;
	void mouseToControl(SDL_Event event) override;
private:
	/* Actors */
	Actor* background;
	Actor* button;
	Crosshair* crosshair;
};

