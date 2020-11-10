#include "Player.h"

Player::Player(float x, float y, int* mouseX, int* mouseY, int* scrollX, int* scrollY, Game* game) : 
	Character("res/sprites/player/Character_Idle_Down.png", x, y, 16, 16, game) 
{
	this->type = PLAYER;
	// Set references
	this->mouseX = mouseX;
	this->mouseY = mouseY;
	this->scrollX = scrollX;
	this->scrollY = scrollY;
	// Set stats
	this->hp = STARTING_PLAYER_HP;
	this->shotCadence = STARTING_PLAYER_CADENCE;
	this->shotTime = shotCadence;
	this->speed = STARTING_PLAYER_SPEED;
	// Debugging stats
	this->speed = 3;

	importAnimations();
	// State initialization
	this->action = IDLE;
	this->orientation = DOWN;
	this->animation = idleAnimations[orientation];
}

Player::~Player() {
	idleAnimations.clear();
	shootingAnimations.clear();
}

void Player::update() {
	bool endAnimation = animation->update();
	shotTime--;
	// Player update
	setAction(endAnimation);			// Sets the action performed by the player
	setOrientation();					// Sets the orientation towards the cursor
	setAnimation();						// Sets the new animation
}

void Player::collisionedWith(Actor* actor) {
	if ((actor->type == ENEMY || actor->type == ENEMY_PROJECTILE) && !actor->destructionFlag) {
		damage();
	}
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
		return new Projectile("res/sprites/player/Player_Projectile.png", 
			x, y, mouseX, mouseY, 7, game);
	}
	return nullptr;
}

void Player::setAction(bool endAction) {
	if (this->action == SHOOTING && !endAction)
		return;
	else if (vx != 0 || vy != 0)	
		this->action = MOVING;
	else
		this->action = IDLE;
}

void Player::setOrientation() {
	int orientationX = *mouseX + *scrollX - this->x;
	int orientationY = *mouseY + *scrollY - this->y;
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

void Player::importAnimations() {
	// IDLE
	idleAnimations.clear();
	idleAnimations.insert_or_assign(DOWN, new Animation("res/sprites/player/Character_Idle_Down.png",
		PLAYER_VISUAL_SIZE, PLAYER_VISUAL_SIZE, 128, 32, 8, 4, true, game));
	idleAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/player/Character_Idle_Right.png",
		PLAYER_VISUAL_SIZE, PLAYER_VISUAL_SIZE, 128, 32, 8, 4, true, game));
	idleAnimations.insert_or_assign(LEFT, new Animation("res/sprites/player/Character_Idle_Left.png",
		PLAYER_VISUAL_SIZE, PLAYER_VISUAL_SIZE, 128, 32, 8, 4, true, game));
	idleAnimations.insert_or_assign(UP, new Animation("res/sprites/player/Character_Idle_Up.png",
		PLAYER_VISUAL_SIZE, PLAYER_VISUAL_SIZE, 128, 32, 8, 4, true, game));
	// MOVING
	movingAnimations.clear();
	movingAnimations.insert_or_assign(DOWN, new Animation("res/sprites/player/Character_Moving_Down.png",
		PLAYER_VISUAL_SIZE, PLAYER_VISUAL_SIZE, 128, 32, 4, 4, true, game));
	movingAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/player/Character_Moving_Right.png",
		PLAYER_VISUAL_SIZE, PLAYER_VISUAL_SIZE, 128, 32, 4, 4, true, game));
	movingAnimations.insert_or_assign(LEFT, new Animation("res/sprites/player/Character_Moving_Left.png",
		PLAYER_VISUAL_SIZE, PLAYER_VISUAL_SIZE, 128, 32, 4, 4, true, game));
	movingAnimations.insert_or_assign(UP, new Animation("res/sprites/player/Character_Moving_Up.png",
		PLAYER_VISUAL_SIZE, PLAYER_VISUAL_SIZE, 128, 32, 4, 4, true, game));
	// SHOOTING
	shootingAnimations.clear();
	shootingAnimations.insert_or_assign(DOWN, new Animation("res/sprites/player/Character_Shooting_Down.png",
		PLAYER_VISUAL_SIZE, PLAYER_VISUAL_SIZE, 160, 32, 4, 5, false, game));
	shootingAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/player/Character_Shooting_Right.png",
		PLAYER_VISUAL_SIZE, PLAYER_VISUAL_SIZE, 160, 32, 4, 5, false, game));
	shootingAnimations.insert_or_assign(LEFT, new Animation("res/sprites/player/Character_Shooting_Left.png",
		PLAYER_VISUAL_SIZE, PLAYER_VISUAL_SIZE, 160, 32, 4, 5, false, game));
	shootingAnimations.insert_or_assign(UP, new Animation("res/sprites/player/Character_Shooting_Up.png",
		PLAYER_VISUAL_SIZE, PLAYER_VISUAL_SIZE, 160, 32, 4, 5, false, game));
}