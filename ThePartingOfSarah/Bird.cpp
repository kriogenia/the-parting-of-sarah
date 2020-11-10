#include "Bird.h"

Bird::Bird(float x, float y, Actor* player, Game* game) :
	Enemy("res/sprites/bird/Bird_Moving_Left.png", x, y, 32, 32, player, game)
{
	this->flying = true;
	this->hp = BIRD_STARTING_HP;
	this->speed = BIRD_MAX_SPEED;

	importAnimations();
	this->animation = movingAnimations[LEFT];
}

void Bird::setMovement() {
	float velocity = (BIRD_MAX_SPEED - BIRD_FLOOR_SPEED) / BIRD_MAX_RANGE;
	this->speed = BIRD_FLOOR_SPEED + velocity * abs(player->x - x + player->y - y) / 2;
	Enemy::setMovement();
}

void Bird::importAnimations() {
	movingAnimations.clear();
	movingAnimations.insert_or_assign(LEFT, new Animation("res/sprites/bird/Bird_Moving_Left.png",
		width, height, 288, 32, 4, 9, true, game));
	movingAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/bird/Bird_Moving_Right.png",
		width, height, 288, 32, 4, 9, true, game));
	hitAnimations.clear();
	hitAnimations.insert_or_assign(LEFT, new Animation("res/sprites/bird/Bird_Hit_Left.png",
		width, height, 160, 32, 2, 5, false, game));
	hitAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/bird/Bird_Hit_Right.png",
		width, height, 160, 32, 2, 5, false, game));
}