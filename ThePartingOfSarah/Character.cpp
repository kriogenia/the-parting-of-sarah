#include "Character.h"

Character::Character(string filename, float x, float y, int width, int height, Game* game) :
	Actor(filename, x, y, width, height, game) 
{
	this->flying = false;
	observers.clear();
}

Character::~Character() {
	movingAnimations.clear();
	observers.clear();
}

void Character::update() {
	bool endAnimation = animation->update();
	if (this->action == DYING && endAnimation) {
		this->destructionFlag = true;
		return;
	}
	setMovement();
	setAction(endAnimation);
	setOrientation();
	setAnimation();
}

void Character::draw(int scrollX, int scrollY, float rotation) {
	animation->draw(x - scrollX, y - scrollY);
}

void Character::damage(float damage) {
	this->hp -= damage;
	if (hp <= 0) {
		this->destructionFlag = true;
	}
}

void Character::setMovement() {
	this->vx = 0;
	this->vy = 0;
}

void Character::setAction(bool endedAction) {
	this->action = MOVING;
}

void Character::setOrientation() {
	this->orientation = LEFT;
}

void Character::setAnimation() {
	if (this->action == MOVING) {
		this->animation = movingAnimations[orientation];
	}
}