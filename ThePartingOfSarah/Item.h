#pragma once

#include "Player.h"

constexpr auto ITEM_SIZE = 16;

/* Interface */
class Item :
    public Actor
{
public:
	Item(string filename, float x, float y, Game* game);
	/* Actor */
	void collisionedWith(Actor* actor) override;
	/* Item interface */
	virtual Item* getCopy(float x, float y) = 0;
	/* Attributes */
	string name;
	string subtitle;

protected:
	/* Item interface */
	virtual void applyEffect(Player* player) = 0;
	virtual void notify(Player* player);
};