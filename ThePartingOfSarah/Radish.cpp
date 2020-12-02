#include "Radish.h"

Radish::Radish(float x, float y, Environment* room, Game* game) :
	Enemy("res/sprites/raddish/Radish_Idle.png", x, y, 30, 38, room, game)
{
	importAnimations();

	this->points = RADISH_POINTS;
	this->hp = RADISH_HP;
	this->speed = RADISH_SPEED;

	this->animation = movingAnimations[LEFT];
}

Radish::~Radish()
{
	delete idleAnimation;
}

void Radish::setAction(bool endedAction)
{
	if (endedAction) {
		if (this->action == MOVING) {
			this->action = IDLE;
			this->animation = idleAnimation;
		}
		else if (this->action == IDLE || this->action == HIT) {
			this->action = MOVING;
		}
	}
}

void Radish::importAnimations()
{
	dyingAnimation = new Animation("res/sprites/radish/Radish_Dying.png",
		width, height, 180, 38, 4, 6, false, game);
	idleAnimation = new Animation("res/sprites/radish/Radish_Idle.png",
		width, height, 180, 38, 4, 6, false, game);
	hitAnimations.clear();
	hitAnimations.insert_or_assign(LEFT, new Animation("res/sprites/radish/Radish_Hit_Left.png",
		width, height, 150, 38, 4, 5, false, game));
	hitAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/radish/Radish_Hit_Right.png",
		width, height, 150, 38, 4, 5, false, game));
	movingAnimations.clear();
	movingAnimations.insert_or_assign(LEFT, new Animation("res/sprites/radish/Radish_Moving_Left.png",
		width, height, 360, 38, 4, 12, false, game));
	movingAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/radish/Radish_Moving_Right.png",
		width, height, 360, 38, 4, 12, false, game));
}