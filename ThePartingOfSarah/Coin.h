#pragma once

#include "Item.h"
#include "Animation.h"

class Coin :
	public Item
{
public:
	Coin(float x, float y, Game* game);

	void draw(int scrollX = 0, int scrollY = 0, float rotation = 0.0) override;

private:
	void applyEffect(Player* player) override;

	Animation* animation;
};