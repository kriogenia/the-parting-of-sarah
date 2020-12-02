#include "Ghost.h"

Ghost::Ghost(float x, float y, Environment* room, Game* game) :
	Enemy("res/sprites/ghost/Ghost_Moving_Left.png", x, y, 44, 30, room, game)
{
	importAnimations();

	this->points = GHOST_POINTS;
	this->hp = GHOST_HP;
	this->speed = GHOST_SPEED;

	this->hidingCooldown = GHOST_HIDING_COOLDOWN;
	this->hidingDuration = GHOST_HIDING_DURATION;

	this->animation = movingAnimations[LEFT];
}

void Ghost::draw(int scrollX, int scrollY, float rotation)
{
	if (this->action == HIDING) {
		return;
	}
	Enemy::draw(scrollX, scrollY, rotation);
}

void Ghost::update()
{
	if (this->action == HIDING) {
		hidingDuration--;
	}
	else {
		hidingCooldown--;
	}
	Enemy::update();
}

void Ghost::setAction(bool endedAction)
{
	if (this->action == MOVING && hidingCooldown <= 0) {
		hidingCooldown = GHOST_HIDING_COOLDOWN;
		this->action = IDLE;
		this->animation = hideAnimations[orientation];
	}
	else if (this->action == IDLE && endedAction) {
		this->action = HIDING;
	}
	else if (this->action == HIDING && hidingDuration <= 0) {
		hidingDuration = GHOST_HIDING_DURATION;
		this->action = MOVING;
	}
}

void Ghost::importAnimations()
{
	dyingAnimation = new Animation("res/sprites/ghost/Ghost_Dying.png",
		width, height, 176, 30, 4, 4, false, game);
	hideAnimations.clear();
	hideAnimations.insert_or_assign(LEFT, new Animation("res/sprites/ghost/Ghost_Hiding_Left.png",
		width, height, 176, 30, 4, 4, false, game));
	hideAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/ghost/Ghost_Hiding_Right.png",
		width, height, 176, 30, 4, 4, false, game));
	hitAnimations.clear();
	hitAnimations.insert_or_assign(LEFT, new Animation("res/sprites/ghost/Ghost_Hit_Left.png",
		width, height, 176, 30, 4, 4, false, game));
	hitAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/ghost/Ghost_Hit_Right.png",
		width, height, 176, 30, 4, 4, false, game));
	movingAnimations.clear();
	movingAnimations.insert_or_assign(LEFT, new Animation("res/sprites/ghost/Ghost_Moving_Left.png",
		width, height, 440, 30, 4, 10, true, game));
	movingAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/ghost/Ghost_Moving_Right.png",
		width, height, 440, 30, 4, 10, true, game));
}