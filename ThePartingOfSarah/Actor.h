#pragma once

#include "Game.h"

enum eActorType {
	PLAYER,
	ENEMY,
	TILE,
	DESTRUCTIBLE_TILE,
	PROJECTILE,
	ENEMY_PROJECTILE,
	HUD,
	BACKGROUND,
	ITEM
};

class Actor
{
public:
	Actor(string filename, float x, float y, int width, int height, Game* game);
	Actor(string filename, float x, float y, int width, int height, int fileWidth, int fileHeight, Game* game);
	~Actor();
	/* Game cycle */
	virtual void draw(int scrollX = 0, int scrollY = 0, float rotation = 0.0);
	/* Actor interactions */
	bool containsPoint(int pointX, int pointY);
	bool isOverlap(Actor* actor);
	virtual void collisionedWith(Actor* actor) {};
	/* Game modules*/
	Game* game;
	/* Drawing*/
	SDL_Texture* texture;
	int fileWidth;
	int fileHeight;
	/* Attributes */
	eActorType type;
	bool destructionFlag;		
	float x;					// position on X axis
	float y;					// position on Y axis
	float vx = 0;				// movement on X axis
	float vy = 0;				// movement on Y axis
	int width;					// actor width
	int height;					// actor height

};
