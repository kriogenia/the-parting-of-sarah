#include "Coin.h"

constexpr auto COIN_SIZE = 16;

Coin::Coin(float x, float y, Game* game) :
	Actor("res/items/coin.png", x, y, COIN_SIZE, COIN_SIZE, game)
{
	this->animation = new Animation("res/items/coin.png", COIN_SIZE, COIN_SIZE, 64, 16, 4, 4, true, game);
}

void Coin::draw(int scrollX, int scrollY, float rotation) {
	animation->update();
	animation->draw(x - scrollX, y - scrollY);
}

void Coin::collisionedWith(Actor* actor) {
	if (actor->type == PLAYER) {
		destructionFlag = true;
	}
}