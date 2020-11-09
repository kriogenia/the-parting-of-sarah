#include "Enemy.h"

Enemy::Enemy(string filename, float x, float y, int width, int height, Actor* player, Game* game) :
	Character(filename, x, y, width, height, game) 
{
	this->type = ENEMY;
	this->player = player;
}

void Enemy::collisionedWith(Actor* actor) {
	if (actor->type == PROJECTILE) {
		damage();
	}
}

void Enemy::setMovement() {
	float vectorLength = sqrt(pow(player->x - x, 2) + pow(player->y - y, 2));
	this->vx = (player->x - x) / vectorLength * speed;
	this->vy = (player->y - y) / vectorLength * speed;
}

void Enemy::setOrientation() {
	if (player->x > this->x)
		this->orientation = RIGHT;
	else
		this->orientation = LEFT;
}