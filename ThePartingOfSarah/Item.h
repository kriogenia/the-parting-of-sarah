#pragma once

#include "Player.h"

constexpr auto ITEM_SIZE = 16;

class Item :
    public Actor
{
public:
	Item(string filename, float x, float y, Game* game);

	void collisionedWith(Actor* actor) override;

protected:
	virtual void applyEffect(Player* player) = 0;
};