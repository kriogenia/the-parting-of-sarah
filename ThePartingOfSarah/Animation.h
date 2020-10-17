#pragma once

#include "Game.h"

class Animation {
public:
	Animation(string filename, float actorWidth, float actorHeight,
		float fileWidth, float fileHeight, 
		int updateFrequence, int totalFrames, Game* game);

	bool update();
	void draw(float x, float y);

private:

	Game* game;

	int actorWidth;								// Actor Width
	int actorHeight;							// Actor height
	int fileWidth;								// Sprite Sheet width
	int fileHeight;								// Sprite Sheet height
	int currentFrame;
	int totalFrames;

	SDL_Texture* texture;						// Image
	SDL_Rect source;							// Rectangle view
	float frameWidth;							
	float frameHeigt; 
	int updateFrequence = 0;
	int updateTime = 0;
};
