#include "Bird.h"

Bird::Bird(float x, float y, Environment* room, Game* game) :
	Enemy("res/sprites/bird/Bird_Moving_Left.png", x, y, 32, 32, room, game)
{
	importAnimations();

	this->flying = true;
	this->points = BIRD_POINTS;
	this->hp = BIRD_HP;
	this->speed = BIRD_MAX_SPEED;

	this->animation = movingAnimations[LEFT];
}

void Bird::setMovement() {
	float velocity = (BIRD_MAX_SPEED - BIRD_FLOOR_SPEED) / BIRD_MAX_RANGE;
	this->speed = BIRD_FLOOR_SPEED + velocity * abs(room->player->x - x + room->player->y - y) / 2;
	Enemy::setMovement();
}

void Bird::importAnimations() {
	dyingAnimation = new Animation("res/sprites/bird/Bird_Dying.png",
		width, height, 160, 32, 0, 5, false, game);
	hitAnimations.clear();
	hitAnimations.insert_or_assign(LEFT, new Animation("res/sprites/bird/Bird_Hit_Left.png",
		width, height, 160, 32, 2, 5, false, game));
	hitAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/bird/Bird_Hit_Right.png",
		width, height, 160, 32, 2, 5, false, game));
	movingAnimations.clear();
	movingAnimations.insert_or_assign(LEFT, new Animation("res/sprites/bird/Bird_Moving_Left.png",
		width, height, 288, 32, 4, 9, true, game));
	movingAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/bird/Bird_Moving_Right.png",
		width, height, 288, 32, 4, 9, true, game));
}