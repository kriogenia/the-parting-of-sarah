#include "FireItem.h"

FireItem::FireItem(float x, float y, Game* game) :
	Item("res/items/bluefire.png", x, y, game)
{
	this->name = "Kamespren";
	this->subtitle = "Disparo más pequeño pero más rápido";
}

Item* FireItem::getCopy(float x, float y)
{
	return new FireItem(x, y, game);
}

void FireItem::applyEffect(Player* player)
{
	player->projectileFile = PLAYER_PROJECTILE_FILE_ALT;
	player->shotSize = STARTING_PLAYER_PROJECTILE_SIZE - 2;
	if (player->shotCadence >= CAP_PLAYER_SHOT_CADENCE) {
		player->shotCadence /= 2;
	}
	player->print();
}