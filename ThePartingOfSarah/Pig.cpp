#include "Pig.h"

Pig::Pig(float x, float y, Actor* player, Game* game) :
	Enemy("res/sprites/pig/Pig_Moving_Left.png", x, y, 36, 30, player, game) 
{
	this->hp = PIG_STARTING_HP;
	this->speed = PIG_MOVING_SPEED;

	importAnimations();
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
	this->action = (hp != PIG_STARTING_HP) ? RUNNING : MOVING;
}

void Pig::setAnimation() {
	if (this->action == RUNNING) {
		this->animation = runningAnimations[orientation];
	}
	Enemy::setAnimation();
}

void Pig::importAnimations() {
	movingAnimations.clear();
	movingAnimations.insert_or_assign(LEFT, new Animation("res/sprites/pig/Pig_Moving_Left.png",
		36, 30, 576, 30, 4, 16, true, game));
	movingAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/pig/Pig_Moving_Right.png",
		36, 30, 576, 30, 4, 16, true, game));
	hitAnimations.clear();
	hitAnimations.insert_or_assign(LEFT, new Animation("res/sprites/pig/Pig_Hit_Left.png",
		36, 30, 180, 30, 4, 5, false, game));
	hitAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/pig/Pig_Hit_Right.png",
		36, 30, 180, 30, 4, 5, false, game));
	runningAnimations.clear();
	runningAnimations.insert_or_assign(LEFT, new Animation("res/sprites/pig/Pig_Running_Left.png",
		36, 30, 432, 30, 2, 12, false, game));
	runningAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/pig/Pig_Running_Right.png",
		36, 30, 432, 30, 2, 12, false, game));
}