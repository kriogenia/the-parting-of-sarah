#include "Snail.h"

Snail::Snail(float x, float y, Actor* player, Game* game) :
	Enemy("res/sprites/snail/Snail_Moving.png", x, y, 38, 24, player, game) 
{
	this->hp = SNAIL_STARTING_HP;
	this->speed = SNAIL_SPEED;
	this->timeToHide = SNAIL_INVULNERATIBILITY_CD;

	importAnimations();

	this->action = MOVING;
	this->orientation = LEFT;
	this->animation = movingAnimations[LEFT];
}

Snail::~Snail() {
	delete hidingAnimation;
}

void Snail::update() {
	if (this->action == MOVING)
		timeToHide--;
	Enemy::update();
}

void Snail::damage() {
	if (this->action == HIDING)
		return;
	Enemy::damage();
}

void Snail::setMovement() {
	if (this->action == HIDING) {
		this->vx = 0;
		this->vy = 0;
	}
	else {
		Enemy::setMovement();
	}
}

void Snail::setAction(bool endAction) {
	if (this->action != MOVING && !endAction)
		return;
	if (timeToHide <= 0) {
		timeToHide = SNAIL_INVULNERATIBILITY_CD;
		this->action = HIDING;
	}
	else {
		this->action = MOVING;
	}
}

void Snail::setAnimation() {
	if (this->action == HIDING)
		this->animation = hidingAnimation;
	else
		Enemy::setAnimation();
}

void Snail::importAnimations() {
	hidingAnimation = new Animation("res/sprites/snail/Snail_Hiding.png", 38, 24, 228, 24, 8, 6, false, game);
	movingAnimations.clear();
	movingAnimations.insert_or_assign(LEFT, new Animation("res/sprites/snail/Snail_Moving_Left.png",
		38, 24, 380, 24, 8, 10, true, game));
	movingAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/snail/Snail_Moving_Right.png",
		38, 24, 380, 24, 8, 10, true, game));
	hitAnimations.clear();
	hitAnimations.insert_or_assign(LEFT, new Animation("res/sprites/snail/Snail_Hit_Left.png",
		38, 24, 190, 24, 4, 5, false, game));
	hitAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/snail/Snail_Hit_Right.png",
		38, 24, 190, 24, 4, 5, false, game));
}