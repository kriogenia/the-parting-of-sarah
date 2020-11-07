#include "Player.h"

Player::Player(float x, float y, Game* game) : 
	Actor("res/sprites/character/Character_Idle_Down.png", x, y, 16, 16, game) 
{
	this->type = PLAYER;

	//this->speed = STARTING_SPEED;
	this->shotCadence = STARTING_CADENCE;
	this->shotTime = shotCadence;

	this->speed = DEBUGGING_SPEED;

	this->importAnimations();

	this->action = IDLE;
	this->orientation = DOWN;
	this->animation = idleAnimations[orientation];

}

Player::~Player() {
	movingAnimations.clear();
	delete animation;
}

void Player::update(int mouseX, int mouseY) {
	bool endAnimation = animation->update();
	shotTime--;
	// Player update
	setAction(endAnimation);		// Sets the action performed by the player
	setOrientation(mouseX, mouseY);	// Sets the orientation towards the cursor
	setAnimation();					// Sets the new animation
}

void Player::draw(float scrollX, float scrollY) {
	animation->draw(x - scrollX, y - scrollY);
}

void Player::enterInput(int code) {
	switch (code) {
	case SDLK_w:				// up
		moveUp = -1;
		break;
	case SDLK_a:				// left
		moveLeft = -1;
		break;
	case SDLK_s:				// down
		moveDown = 1;
		break;
	case SDLK_d:				// right
		moveRight = 1;
		break;
	case SDL_MOUSEBUTTONDOWN:
		shooting = true;
		break;
	}
}

void Player::stopInput(int code) {
	switch (code) {
	case SDLK_w:				// up
		moveUp = 0;
		break;
	case SDLK_a:				// left
		moveLeft = 0;
		break;
	case SDLK_s:				// down
		moveDown = 0;
		break;
	case SDLK_d:				// right
		moveRight = 0;
		break;
	case SDL_MOUSEBUTTONUP:
		shooting = false;
		break;
	}
}

void Player::move() {
	vx = (moveLeft + moveRight) * speed;
	vy = (moveUp + moveDown) * speed;
}

Projectile* Player::shoot(int mouseX, int mouseY) {
	if (shooting && shotTime <= 0) {
		shotTime = shotCadence;
		this->action = SHOOTING;
		this->animation = shootingAnimations[this->orientation];
		return new Projectile("res/sprites/projectiles/player_projectile.png", 
			x, y, mouseX, mouseY, 7, game);
	}
	return nullptr;
}

void Player::importAnimations() {
	// IDLE
	idleAnimations.clear();
	idleAnimations.insert_or_assign(DOWN, new Animation("res/sprites/character/Character_Idle_Down.png", 
		width, height, 64, 16, 8, 4, true, game));
	idleAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/character/Character_Idle_Right.png", 
		width, height, 64, 16, 8, 4, true, game));
	idleAnimations.insert_or_assign(LEFT, new Animation("res/sprites/character/Character_Idle_Left.png", 
		width, height, 64, 16, 8, 4, true, game));
	idleAnimations.insert_or_assign(UP, new Animation("res/sprites/character/Character_Idle_Up.png", 
		width, height, 64, 16, 8, 4, true, game));
	// MOVING
	movingAnimations.clear();
	movingAnimations.insert_or_assign(DOWN, new Animation("res/sprites/character/Character_Moving_Down.png", 
		width, height, 64, 16, 4, 4, true, game));
	movingAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/character/Character_Moving_Right.png", 
		width, height, 64, 16, 4, 4, true, game));
	movingAnimations.insert_or_assign(LEFT, new Animation("res/sprites/character/Character_Moving_Left.png", 
		width, height, 64, 16, 4, 4, true, game));
	movingAnimations.insert_or_assign(UP, new Animation("res/sprites/character/Character_Moving_Up.png", 
		width, height, 64, 16, 4, 4, true, game));
	// SHOOTING
	shootingAnimations.clear();
	shootingAnimations.insert_or_assign(DOWN, new Animation("res/sprites/character/Character_Shooting_Down.png", 
		width, height, 80, 16, 6, 5, false, game));
	shootingAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/character/Character_Shooting_Right.png", 
		width, height, 80, 16, 6, 5, false, game));
	shootingAnimations.insert_or_assign(LEFT, new Animation("res/sprites/character/Character_Shooting_Left.png", 
		width, height, 80, 16, 6, 5, false, game));
	shootingAnimations.insert_or_assign(UP, new Animation("res/sprites/character/Character_Shooting_Up.png", 
		width, height, 80, 16, 6, 5, false, game));
}

void Player::setAction(bool endAction) {
	if (this->action == SHOOTING && !endAction)
		return;
	else if (vx != 0 || vy != 0)	
		this->action = MOVING;
	else
		this->action = IDLE;
}

void Player::setOrientation(int mouseX, int mouseY) {
	int orientationX = mouseX - this->x;
	int orientationY = mouseY - this->y;
	setAxisOrientation(orientationX, orientationY);
	//(this->action == MOVING) ? 
	//	setDiagonalOrientation(orientationX, orientationY) :
	//	setAxisOrientation(orientationX, orientationY);
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
/*
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
*/
void Player::setAnimation() {
	if		(action == IDLE)	this->animation = idleAnimations[orientation];
	else if (action == MOVING)	this->animation = movingAnimations[orientation];
}