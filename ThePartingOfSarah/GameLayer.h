#pragma once

#include "Crosshair.h"
#include "Layer.h"
#include "Level.h"
#include "Player.h"

class GameLayer : 
	public Layer
{
public:
	GameLayer(Game* game);
	~GameLayer();

	void init() override;
	void processControls() override;
	void update() override;
	void draw() override;

	float scrollX = 0;
	float scrollY = 0;

private:
	void calculateScroll();
	void keysToControl(SDL_Event event);

	Crosshair* crosshair;
	Player* player;
	Level* level;

	int floor = 0;

	int mouseX = 0;
	int mouseY = 0;

};
