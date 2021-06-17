#include "KnifeItem.h"

KnifeItem::KnifeItem(float x, float y, Game* game) :
	Item("res/items/knife.png", x, y, game)
{
	this->name = "Cuchillo de Meru";
	this->subtitle = "M�s da�o";
}

Item* KnifeItem::getCopy(float x, float y)
{
	return new KnifeItem(x, y, game);
}

void KnifeItem::applyEffect(Player* player)
{
	// Not affected by the cap
	player->attack *= KNIFE_ATTACK_MULTIPLIER;
	player->print();
}