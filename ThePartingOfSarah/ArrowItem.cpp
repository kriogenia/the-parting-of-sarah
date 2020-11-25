#include "ArrowItem.h"

ArrowItem::ArrowItem(float x, float y, Game* game) :
	Item("res/items/arrow.png", x, y, game)
{
	this->name = "Saeta";
	this->subtitle = "Damage goes brrrrrrr";
}

Item* ArrowItem::getCopy(float x, float y)
{
	return new ArrowItem(x, y, game);
}

void ArrowItem::applyEffect(Player* player)
{
	player->attack *= ARROW_ATTACK_MULTIPLIER;
	player->print();
}