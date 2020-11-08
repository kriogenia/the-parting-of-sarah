#include "Enemy.h"

Enemy::Enemy(string filename, float x, float y, int width, int height, Game* game) :
	Character(filename, x, y, width, height, game) 
{
	this->type = ENEMY;
}

void Enemy::collisionedWith(Actor* actor) {
	if (actor->type == PROJECTILE) {
		damage();
	}
}