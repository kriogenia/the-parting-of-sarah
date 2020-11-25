#include "Coin.h"

Coin::Coin(float x, float y, Game* game) :
	Item("res/items/coin.png", x, y, game)
{
	this->type = ITEM;
	this->animation = new Animation("res/items/coin.png", ITEM_SIZE, ITEM_SIZE, 64, 16, 4, 4, true, game);
}

void Coin::draw(int scrollX, int scrollY, float rotation) 
{
	animation->update();
	animation->draw(x - scrollX, y - scrollY);
}

Item* Coin::getCopy(float x, float y)
{
	return new Coin(x, y, game);
}

void Coin::applyEffect(Player* player) 
{
	player->coinUp();
}