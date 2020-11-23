#include "Item.h"

Item::Item(string filename, float x, float y, Game* game) :
	Actor(filename, x, y, ITEM_SIZE, ITEM_SIZE, game)
{
	this->type = ITEM;
}

void Item::collisionedWith(Actor* actor) {
	if (actor->type == PLAYER) {
		destructionFlag = true;
		applyEffect((Player*)actor);
	}
}