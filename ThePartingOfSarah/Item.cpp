#include "Item.h"

Item::Item(string filename, float x, float y, Game* game) :
	Actor(filename, x, y, ITEM_SIZE, ITEM_SIZE, game)
{
	this->type = ITEM;
}

void Item::collisionedWith(Actor* actor) {
	if (actor->type == PLAYER) {
		Player* player = (Player*)actor;
		destructionFlag = true;
		applyEffect(player);
		notify(player);
	}
}

void Item::notify(Player* player)
{
	for (auto const& observer : player->observers) {
		observer->notify(NOTIFICATION_PICK_ITEM, this);
	}
}
