#include "Enemy.h"

Enemy::Enemy(string filename, float x, float y, int width, int height, Environment* room, Game* game) :
	Character(filename, x, y, width, height, game) 
{
	this->type = ENEMY;
	this->room = room;

	this->action = MOVING;
	this->orientation = LEFT;
}

Enemy::~Enemy() {
	delete dyingAnimation;
	hitAnimations.clear();
}

void Enemy::collisionedWith(Actor* actor) {
	if (actor->type == PROJECTILE && !actor->destructionFlag) {
		damage(((Projectile*) actor)->damage);
	}
}

void Enemy::damage(float damage) {
	//this->hp = 0;				// Debug
	if (this->action != HIT && this->action != DYING) {
		this->hp -= damage;
		(hp <= 0) ? death() : hit();
	}
}

void Enemy::setMovement() {
	if (this->action == HIT || this->action == DYING) {
		this->vx = 0;
		this->vy = 0;
	}
	else {
		float vectorLength = sqrt(pow(room->player->x - x, 2) + pow(room->player->y - y, 2));
		this->vx = (room->player->x - x) / vectorLength * speed;
		this->vy = (room->player->y - y) / vectorLength * speed;
	}
}

void Enemy::setAction(bool endAction) {
	if (this->action != MOVING && !endAction)
		return;
	this->action = MOVING;
}

void Enemy::setOrientation() {
	if (room->player->x > this->x)
		this->orientation = RIGHT;
	else
		this->orientation = LEFT;
}

void Enemy::death() {
	this->action = DYING;
	this->animation = dyingAnimation;
	if (rand() % COIN_RARITY == 0) {
		room->spawnCoin(x, y);
	}
	for (auto const& observer : observers) {
		observer->notify(NOTIFICATION_ENEMY_KILLED, this);
	}
}

void Enemy::hit() {
	this->action = HIT;
	this->animation = hitAnimations[orientation];
}