#pragma once

#include "Game.h"

enum eActorType {
	PLAYER,
	ENEMY,
	TILE,
	PROJECTILE,
	ENEMY_PROJECTILE,
	HUD,
	BACKGROUND
};

class Actor
{
public:
	Actor(string filename, float x, float y, int width, int height, Game* game);
	Actor(string filename, float x, float y, int width, int height, int fileWidth, int fileHeight, Game* game);
	~Actor();

	virtual void draw(int scrollX = 0, int scrollY = 0);

	bool isOverlap(Actor* actor);
	virtual void collisionedWith(Actor* actor);

	SDL_Texture* texture;
	Game* game;

	eActorType type;

	float x;						
	float y;		

	float vx = 0;				// movement on X axis
	float vy = 0;				// movement on Y axis

	int width;					// actor width
	int height;					// actor height

	int fileWidth;				
	int fileHeight;

	bool destructionFlag;		

};
