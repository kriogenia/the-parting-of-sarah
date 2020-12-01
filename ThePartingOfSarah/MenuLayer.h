#pragma once

#include "Actor.h"
#include "Crosshair.h"
#include "Layer.h"
#include "Text.h"

class MenuLayer :
    public Layer
{
public:
	MenuLayer(Game* game, bool first);
	/* Game cycle */
	void init() override;
	void draw() override;
	void update() override;
	/* Controls */
	void keysToControl(SDL_Event event) override;
	void mouseToControl(SDL_Event event) override;
private:
	bool first;
	/* Modules */
	Actor* background;
	Actor* button;
	Text* points;
	Crosshair* crosshair;
};

