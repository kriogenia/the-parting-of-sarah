#pragma once

#include "AudioPlayer.h"
#include "Hud.h"
#include "HudObserver.h"
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
	// Game cycle
	void init() override;
	void processControls() override;
	void update() override;
	void draw() override;

private:
	// Input control
	void keysToControl(SDL_Event event);
	void mouseToControl(SDL_Event event);

	AudioPlayer* audio;
	Hud* hud;
	Level* level;
	Space* space;
	
	// Actors
	Player* player;
	list<Projectile*> projectiles;

	int floor = 0;

	int scrollX = 0;
	int scrollY = 0;
	int mouseX = 0;
	int mouseY = 0;

};
