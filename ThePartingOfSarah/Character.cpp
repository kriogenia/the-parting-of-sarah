#include "Character.h"

Character::Character(string filename, float x, float y, int width, int height, Game* game) :
	Actor(filename, x, y, width, height, game) {}

Character::Character(string filename, float x, float y, int width, int height, int fileWidth, int fileHeight, Game* game) :
	Actor(filename, x, y, width, height, fileWidth, fileHeight, game) {}

void Character::update() {}

void Character::draw(int scrollX, int scrollY) {
	animation->draw(x - scrollX, y - scrollY);
}