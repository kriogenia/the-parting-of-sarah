#include "FlagItem.h"

FlagItem::FlagItem(float x, float y, Game* game) :
	Item("res/items/flag.png", x, y, game)
{
	this->name = "Banner";
	this->subtitle = "PROMOTION, PROMOTION, PROMOTION";
}

Item* FlagItem::getCopy(float x, float y)
{
	return new FlagItem(x, y, game);
}

void FlagItem::applyEffect(Player* player)
{
	player->powerUp();
	player->powerUp();
	player->powerUp();
}