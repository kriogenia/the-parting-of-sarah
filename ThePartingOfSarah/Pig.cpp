#include "Pig.h"

Pig::Pig(float x, float y, Environment* room, Game* game) :
	Enemy("res/sprites/pig/Pig_Moving_Left.png", x, y, 36, 30, room, game) 
{
	importAnimations();

	this->points = PIG_POINTS;
	this->hp = PIG_HP;
	this->speed = PIG_MOVING_SPEED;

	this->animation = movingAnimations[orientation];
}

Pig::~Pig() {
	runningAnimations.clear();
}

void Pig::setMovement() {
	speed = (this->action == RUNNING) ? PIG_RUNNING_SPEED : PIG_MOVING_SPEED;
	Enemy::setMovement();
}

void Pig::setAction(bool endAction) {
	if ((this->action == HIT || this->action == DYING) && !endAction)
		return;
	this->action = (hp != PIG_HP) ? RUNNING : MOVING;
}

void Pig::setAnimation() {
	if (this->action == RUNNING) {
		this->animation = runningAnimations[orientation];
	}
	Enemy::setAnimation();
}

void Pig::importAnimations() {
	dyingAnimation = new Animation("res/sprites/pig/Pig_Dying.png",
		width, height, 180, 30, 0, 5, false, game);
	hitAnimations.clear();
	hitAnimations.insert_or_assign(LEFT, new Animation("res/sprites/pig/Pig_Hit_Left.png",
		width, height, 180, 30, 2, 5, false, game));
	hitAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/pig/Pig_Hit_Right.png",
		width, height, 180, 30, 2, 5, false, game));
	movingAnimations.clear();
	movingAnimations.insert_or_assign(LEFT, new Animation("res/sprites/pig/Pig_Moving_Left.png",
		width, height, 576, 30, 4, 16, true, game));
	movingAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/pig/Pig_Moving_Right.png",
		width, height, 576, 30, 4, 16, true, game));
	runningAnimations.clear();
	runningAnimations.insert_or_assign(LEFT, new Animation("res/sprites/pig/Pig_Running_Left.png",
		width, height, 432, 30, 2, 12, false, game));
	runningAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/pig/Pig_Running_Right.png",
		width, height, 432, 30, 2, 12, false, game));
}