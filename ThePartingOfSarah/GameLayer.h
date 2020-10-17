#pragma once

#include "Background.h"
#include "Layer.h"
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

	Background* background;
	Player* player;

private:
	void keysToControl(SDL_Event event);

};
