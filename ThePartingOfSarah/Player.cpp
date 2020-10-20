#include "Player.h"

Player::Player(float x, float y, Game* game) : 
	Actor("res/sprites/character/Character_Idle_Down.png", x, y, 64, 64, game) {
	this->speed = STARTING_SPEED;

	movingAnimations.clear();
	movingAnimations.insert_or_assign(DOWN_LEFT, new Animation("res/sprites/character/Character_Moving_DownLeft.png", width, height,
		128, 32, 4, 4, game));
	movingAnimations.insert_or_assign(DOWN_RIGHT, new Animation("res/sprites/character/Character_Moving_DownRight.png", width, height,
		128, 32, 4, 4, game));
	movingAnimations.insert_or_assign(UP_LEFT, new Animation("res/sprites/character/Character_Moving_UpLeft.png", width, height,
		128, 32, 4, 4, game));
	movingAnimations.insert_or_assign(UP_RIGHT, new Animation("res/sprites/character/Character_Moving_UpRight.png", width, height,
		128, 32, 4, 4, game));

	this->orientation = DOWN_RIGHT;
	this->animation = movingAnimations[orientation];
	this->action = MOVING;

}

Player::~Player() {
	movingAnimations.clear();
	delete animation;
}

void Player::update(int mouseX, int mouseY) {
	this->orientation = getOrientation(mouseX, mouseY);	// Sets the orientation towards the cursor
	this->animation = getAnimation();					// Sets the animation
	animation->update();
	x = x + movementX * speed;
	y = y + movementY * speed;
}

void Player::move(int code) {
	switch (code) {
	case SDLK_d:				// right
		movementX = 1;
		break;
	case SDLK_a:				// left
		movementX = -1;
		break;
	case SDLK_w:				// up
		movementY = -1;
		break;
	case SDLK_s:				// down
		movementY = 1;
		break;
	}
}

void Player::draw(float scrollX, float scrollY) {
	animation->draw(x - scrollX, y - scrollY);
}

void Player::stop(int code) {
	switch (code) {
	case SDLK_d:				// right
		if (movementX == 1) {
			movementX = 0;
		}
		break;
	case SDLK_a:				// left
		if (movementX == -1) {
			movementX = 0;
		}
		break;
	case SDLK_w:				// up
		if (movementY == -1) {
			movementY = 0;
		}
		break;
	case SDLK_s:				// down
		if (movementY == 1) {
			movementY = 0;
		}
		break;
	}

}

eOrientation Player::getOrientation(int mouseX, int mouseY) {
	int orientationX = mouseX - this->x;
	int orientationY = mouseY - this->y;
	if (orientationX < 0) {
		if (orientationY < 0)
			return orientation = UP_LEFT;
		return orientation = DOWN_LEFT;
	}
	else {
		if (orientationY < 0)
			return orientation = UP_RIGHT;
		return orientation = DOWN_RIGHT;
	}
}

Animation* Player::getAnimation() {
	//if (action == IDLE)
	if (action == MOVING)
		return movingAnimations[orientation];
	//if (action == SHOOTING)
	return nullptr;
}