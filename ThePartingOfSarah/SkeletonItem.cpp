#include "SkeletonItem.h"

SkeletonItem::SkeletonItem(float x, float y, Game* game) :
	Item("res/items/skeleton.png", x, y, game)
{
	this->name = "Iyanel";
	this->subtitle = "The emo way";
}

Item* SkeletonItem::getCopy(float x, float y)
{
	return new SkeletonItem(x, y, game);
}

void SkeletonItem::applyEffect(Player* player)
{
	player->maxHp --;
	if (player->hp > player->maxHp) {
		player->hp = player->maxHp;
	}
	player->attack++;
	player->shotCadence--;
	player->shotSize++;
	for (auto const& observer : player->observers) {
		observer->notify(NOTIFICATION_PLAYER_HIT, player);
	}
	player->print();
}