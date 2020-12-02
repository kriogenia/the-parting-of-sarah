#pragma once

#include "AudioPlayer.h"
#include "Hud.h"
#include "Layer.h"
#include "Level.h"
#include "Player.h"
#include "Space.h"

class GameLayer : 
	public Layer
{
public:
	GameLayer(Game* game);
	~GameLayer();
	/* Game cycle */
	void init() override;
	void processControls() override;
	void update() override;
	void draw() override;
	/* Layer */
	void keysToControl(SDL_Event event) override;
	void mouseToControl(SDL_Event event) override;
	/* State */
	int pause = false;

private:
	/* Game progression */
	void initFloor();
	void climbUp();
	/* Game modules */
	AudioPlayer* audio;
	Hud* hud;
	Level* level;
	Space* space;
	/* Player actors */
	Player* player;
	list<Projectile*> projectiles;
	/* Level */
	unsigned int floor = 0;
	/* Screen */
	int scrollX = 0;
	int scrollY = 0;

};
