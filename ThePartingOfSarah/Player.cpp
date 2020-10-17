#include "Player.h"

Player::Player(float x, float y, Game* game) : 
	Actor("res/sprites/mc_right.png", x, y, 35, 35, game) {
	this->speed = STARTING_SPEED;
	this->animation = new Animation("res/sprites/mc_right.png", width, height,
		320, 40, 6, 8, game);
}

void Player::update() {
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

void Player::draw() {
	animation->draw(x, y);
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