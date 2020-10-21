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

	int scrollX = 0;
	int scrollY = 0;

private:
	void keysToControl(SDL_Event event);

	Crosshair* crosshair;
	Player* player;
	Level* level;

	int floor = 0;

	int mouseX = 0;
	int mouseY = 0;

};
