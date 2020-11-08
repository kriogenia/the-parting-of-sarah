#include "Character.h"

Character::Character(string filename, float x, float y, int width, int height, Game* game) :
	Actor(filename, x, y, width, height, game) {}

Character::~Character() {
	movingAnimations.clear();
	delete animation;
}

void Character::update() {}

void Character::draw(int scrollX, int scrollY) {
	animation->draw(x - scrollX, y - scrollY);
}

void Character::damage() {
	this->hp--;
	if (hp <= 0) {
		this->destructionFlag = true;
	}
}

void Character::importAnimations() {}