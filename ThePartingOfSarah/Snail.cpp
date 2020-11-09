#include "Snail.h"

Snail::Snail(float x, float y, Actor* player, Game* game) :
	Enemy("res/sprites/snail/Snail_Moving.png", x, y, 38, 24, player, game) 
{
	this->hp = SNAIL_HP;
	this->speed = SNAIL_SPEED;
	this->timeToHide = SNAIL_INVULNERATIBILITY_CD;

	importAnimations();

	this->action = MOVING;
	this->orientation = LEFT;
	this->animation = movingAnimations[LEFT];
}

void Snail::importAnimations() {
	movingAnimations.clear();
	movingAnimations.insert_or_assign(LEFT, new Animation("res/sprites/snail/Snail_Moving_Left.png",
		38, 24, 380, 24, 8, 10, false, game));
	movingAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/snail/Snail_Moving_Right.png",
		38, 24, 380, 24, 8, 10, false, game));
}