#include "KnifeItem.h"

KnifeItem::KnifeItem(float x, float y, Game* game) :
	Item("res/items/knife.png", x, y, game)
{
	this->name = "Meru's razor";
	this->subtitle = "Damage goes brrrrrrr";
}

Item* KnifeItem::getCopy(float x, float y)
{
	return new KnifeItem(x, y, game);
}

void KnifeItem::applyEffect(Player* player)
{
	player->attack *= KNIFE_ATTACK_MULTIPLIER;
	player->print();
}