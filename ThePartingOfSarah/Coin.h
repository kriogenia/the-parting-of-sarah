#pragma once

#include "Actor.h"
#include "Animation.h"

class Coin :
	public Actor
{
public:
	Coin(float x, float y, Game* game);

	void draw(int scrollX = 0, int scrollY = 0, float rotation = 0.0) override;

	void collisionedWith(Actor* actor) override;

private:
	Animation* animation;
};