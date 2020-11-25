#pragma once

#include "Item.h"
#include "Animation.h"

class Coin :
	public Item
{
public:
	Coin(float x, float y, Game* game);
	/* Game cycle */
	void draw(int scrollX = 0, int scrollY = 0, float rotation = 0.0) override;
	/* Item */
	Item* getCopy(float x, float y) override;

private:
	void applyEffect(Player* player) override;

	Animation* animation;
};