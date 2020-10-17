#include "Player.h"

Player::Player(float x, float y, Game* game) : 
	Actor("res/sprites/mc_front.png", x, y, 66, 92, game) {
	this->speed = STARTING_SPEED;
}

void Player::update() {
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