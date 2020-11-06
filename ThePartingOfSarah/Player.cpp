#include "Player.h"

Player::Player(float x, float y, Game* game) : 
	Actor("res/sprites/character/Character_Idle_Down.png", x, y, 32, 32, game) {
	//this->speed = STARTING_SPEED;
	this->speed = DEBUGGING_SPEED;

	this->importAnimations();

	this->action = IDLE;
	this->orientation = DOWN;
	setAnimation();

}

Player::~Player() {
	movingAnimations.clear();
	delete animation;
}

void Player::update(int mouseX, int mouseY) {
	setAction();					// Sets the action performed by the player
	setOrientation(mouseX, mouseY);	// Sets the orientation towards the cursor
	setAnimation();					// Sets the animation
	animation->update();
}

void Player::draw(float scrollX, float scrollY) {
	animation->draw(x - scrollX, y - scrollY);
}

void Player::move(int code) {
	switch (code) {
	case SDLK_d:				// right
		vx = speed;
		break;
	case SDLK_a:				// left
		vx = -speed;
		break;
	case SDLK_w:				// up
		vy = -speed;
		break;
	case SDLK_s:				// down
		vy = speed;
		break;
	}
}

void Player::stop(int code) {
	switch (code) {
	case SDLK_d:				// right
		if (vx == speed) {
			vx = 0;
		}
		break;
	case SDLK_a:				// left
		if (vx == -speed) {
			vx = 0;
		}
		break;
	case SDLK_w:				// up
		if (vy == -speed) {
			vy = 0;
		}
		break;
	case SDLK_s:				// down
		if (vy == speed) {
			vy = 0;
		}
		break;
	}

}

void Player::importAnimations() {
	// IDLE
	idleAnimations.clear();
	idleAnimations.insert_or_assign(DOWN, new Animation("res/sprites/character/Character_Idle_Down.png", width, height,
		128, 32, 4, 4, game));
	idleAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/character/Character_Idle_Right.png", width, height,
		128, 32, 4, 4, game));
	idleAnimations.insert_or_assign(LEFT, new Animation("res/sprites/character/Character_Idle_Left.png", width, height,
		128, 32, 4, 4, game));
	idleAnimations.insert_or_assign(UP, new Animation("res/sprites/character/Character_Idle_Up.png", width, height,
		128, 32, 4, 4, game));
	// MOVING
	movingAnimations.clear();
	movingAnimations.insert_or_assign(DOWN_LEFT, new Animation("res/sprites/character/Character_Moving_DownLeft.png", width, height,
		128, 32, 4, 4, game));
	movingAnimations.insert_or_assign(DOWN_RIGHT, new Animation("res/sprites/character/Character_Moving_DownRight.png", width, height,
		128, 32, 4, 4, game));
	movingAnimations.insert_or_assign(UP_LEFT, new Animation("res/sprites/character/Character_Moving_UpLeft.png", width, height,
		128, 32, 4, 4, game));
	movingAnimations.insert_or_assign(UP_RIGHT, new Animation("res/sprites/character/Character_Moving_UpRight.png", width, height,
		128, 32, 4, 4, game));
}

void Player::setAction() {
	if (vx != 0 || vy != 0)
		this->action = MOVING;
	else
		this->action = IDLE;
}

void Player::setOrientation(int mouseX, int mouseY) {
	int orientationX = mouseX - this->x;
	int orientationY = mouseY - this->y;
	if		(this->action == IDLE)		setAxisOrientation(orientationX, orientationY);
	else if (this->action == MOVING)	setDiagonalOrientation(orientationX, orientationY);
	
}

void Player::setAxisOrientation(int orientationX, int orientationY) {
	if (abs(orientationX) > abs(orientationY)) {
		if (orientationX > 0)
			this->orientation = RIGHT;
		else
			this->orientation = LEFT;
	}
	else {
		if (orientationY > 0)
			this->orientation = DOWN;
		else 
			this->orientation = UP;
	}
}

void Player::setDiagonalOrientation(int orientationX, int orientationY) {
	if (orientationX < 0)
		if (orientationY < 0)
			this->orientation = UP_LEFT;
		else
			this->orientation = DOWN_LEFT;
	else
		if (orientationY < 0)
			this->orientation = UP_RIGHT;
		else
			this->orientation = DOWN_RIGHT;
}

void Player::setAnimation() {
	if		(action == IDLE)	this->animation = idleAnimations[orientation];
	else if (action == MOVING)	this->animation = movingAnimations[orientation];
}