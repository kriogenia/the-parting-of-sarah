#include "Enemy.h"

Enemy::Enemy(string filename, float x, float y, int width, int height, Actor* player, Game* game) :
	Character(filename, x, y, width, height, game) 
{
	this->type = ENEMY;
	this->player = player;

	this->action = MOVING;
	this->orientation = LEFT;
}

Enemy::~Enemy() {
	delete dyingAnimation;
	hitAnimations.clear();
}

void Enemy::collisionedWith(Actor* actor) {
	if (actor->type == PROJECTILE && !actor->destructionFlag) {
		damage();
	}
}

void Enemy::damage() {
	if (this->action != HIT || this->action != DYING) {
		this->hp--;
		if (hp <= 0) {
			this->action = DYING;
			this->animation = dyingAnimation;
		}
		else {
			this->action = HIT;
			this->animation = hitAnimations[orientation];
		}
	}
}

void Enemy::setMovement() {
	if (this->action == HIT || this->action == DYING) {
		this->vx = 0;
		this->vy = 0;
	}
	else {
		float vectorLength = sqrt(pow(player->x - x, 2) + pow(player->y - y, 2));
		this->vx = (player->x - x) / vectorLength * speed;
		this->vy = (player->y - y) / vectorLength * speed;
	}
}

void Enemy::setAction(bool endAction) {
	if (this->action != MOVING && !endAction)
		return;
	this->action = MOVING;
}

void Enemy::setOrientation() {
	if (player->x > this->x)
		this->orientation = RIGHT;
	else
		this->orientation = LEFT;
}