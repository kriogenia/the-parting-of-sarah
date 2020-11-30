#include "HeartItem.h"

HeartItem::HeartItem(float x, float y, Game* game) :
	Item("res/items/potion.png", x, y, game)
{
	this->name = "Nareda";
	this->subtitle = "<3 <3 <3";
}

Item* HeartItem::getCopy(float x, float y)
{
	return new HeartItem(x, y, game);
}

void HeartItem::applyEffect(Player* player)
{
	player->maxHp += 3;
	if (player->maxHp > CAP_PLAYER_HP) {
		player->maxHp = CAP_PLAYER_HP;
	}
	player->hp = player->maxHp;
	for (auto const& observer : player->observers) {
		observer->notify(NOTIFICATION_PLAYER_HEAL, player);
	}
	player->print();
}