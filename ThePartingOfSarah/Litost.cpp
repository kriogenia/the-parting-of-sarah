#include "Litost.h"

Litost::Litost(float x, float y, Environment* room, Game* game) :
	Boss("res/sprites/litost/Litost_Moving.png", x, y, 64, 64, room, game)
{
	importAnimations();

	this->name = "Litost";
	this->subtitle = "He cooks";

	this->maxHp = LITOST_HP;
	this->hp = maxHp;
	this->speed = 0;

	this->animation = movingAnimations[LEFT];
}

void Litost::setOrientation()
{
}

void Litost::importAnimations()
{
	dyingAnimation = new Animation("res/sprites/litost/Litost_Dying.png",
		width, height, 264, 64, 4, 4, false, game);
	movingAnimations.clear();
	movingAnimations.insert_or_assign(LEFT, new Animation("res/sprites/litost/Litost_Moving.png",
		width, height, 264, 64, 4, 4, true, game));
}