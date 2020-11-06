#pragma once

#include "Game.h"

class Actor
{
public:
	Actor(string filename, float x, float y, int width, int height, Game* game);
	Actor(string filename, float x, float y, int width, int height, int fileWidth, int fileHeight, Game* game);
	~Actor();

	virtual void draw(float scrollX = 0, float scrollY = 0);

	SDL_Texture* texture;
	int x;						
	int y;						
	int vx = 0;					// movement on X axis
	int vy = 0;					// movement on Y axis
	int width;					// actor width
	int height;					// actor height
	int fileWidth;				
	int fileHeight;
	Game* game;					// referencia al juego

};
