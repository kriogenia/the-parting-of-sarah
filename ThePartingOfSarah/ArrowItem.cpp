#include "ArrowItem.h"

ArrowItem::ArrowItem(float x, float y, Game* game) :
	Item("res/items/arrow.png", x, y, game)
{
	this->name = "Flecha verde GRP";
	this->subtitle = "Más disparos";
}

Item* ArrowItem::getCopy(float x, float y)
{
	return new ArrowItem(x, y, game);
}

void ArrowItem::applyEffect(Player* player)
{
	if (player->numberOfProjectiles <= CAP_PLAYER_PROJECTILES) {
		player->numberOfProjectiles++;
	}
}