#include "ShieldItem.h"

ShieldItem::ShieldItem(float x, float y, Game* game) :
	Item("res/items/shield.png", x, y, game)
{
	this->name = "Shield of Xur";
	this->subtitle = "It blocks! ... sometimes, I think?";
}

Item* ShieldItem::getCopy(float x, float y) 
{
	return new ShieldItem(x, y, game);
}

void ShieldItem::applyEffect(Player* player)
{
	if (player->shieldCd < 0) {
		player->shieldCd = DEFAULT_SHIELD_CD;
	}
	else {
		if (player->shieldCd - SHIELD_CD_REDUCTION >= SHIELD_CD_CAP) {
			player->shieldCd -= SHIELD_CD_REDUCTION;
		}
	}
}