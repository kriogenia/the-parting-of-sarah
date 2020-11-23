#include "Player.h"

Player::Player(float x, float y, int* mouseX, int* mouseY, int* scrollX, int* scrollY, Game* game) : 
	Character("res/sprites/player/Character_Idle_Down.png", x, y, 16, 16, game) 
{
	this->type = PLAYER;
	importAnimations();
	// Set references
	this->mouseX = mouseX;
	this->mouseY = mouseY;
	this->scrollX = scrollX;
	this->scrollY = scrollY;
	// Set stats
	this->attack = STARTING_PLAYER_ATTACK;
	this->hp = STARTING_PLAYER_HP;
	this->maxHp = STARTING_PLAYER_HP;
	this->shotCadence = STARTING_PLAYER_SHOT_CADENCE;
	this->speed = STARTING_PLAYER_SPEED;
	this->shotSize = STARTING_PLAYER_PROJECTILE_SIZE;
	this->coins = 0;
	// Debugging
	printPlayer();
	this->attack = 5;
	this->speed = 5;
	// State initialization
	this->invulnerabilityTime = 0;
	this->shotTime = shotCadence;
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
	invulnerabilityTime--;
	/* Player update */
	setAction(endAnimation);			// Sets the action performed by the player
	setOrientation();					// Sets the orientation towards the cursor
	setAnimation();						// Sets the new animation
}

void Player::draw(int scrollX, int scrollY, float rotation) {
	if (invulnerabilityTime <= 0 || 
		invulnerabilityTime % 10 >= 0 && 
		invulnerabilityTime % 10 <= 5)
			Character::draw(scrollX, scrollY, rotation);
}

void Player::collisionedWith(Actor* actor) {
	if ((actor->type == ENEMY || actor->type == ENEMY_PROJECTILE) && !actor->destructionFlag) {
		damage();
	}
	else if (actor->type == COIN) {
		coinUp();
	}
}

void Player::damage(float damage) {
	if (invulnerabilityTime <= 0) {
		invulnerabilityTime = PLAYER_INVULNERABILITY_TIME;
		Character::damage();
		for (auto const& observer : observers) {
			observer->notify(NOTIFICATION_PLAYER_HIT, this);
		}
	}
}

void Player::coinUp() {
	coins++;
	cout << "Picked up coin. Coins: " << coins << endl;
	if (coins >= 5 && hp < maxHp) {
		hp++;
		cout << "Healed up using five 5 coins. HP: " << hp << "/" << maxHp << " - Coins: " << coins << endl;
		for (auto const& observer : observers) {
			observer->notify(NOTIFICATION_PLAYER_HEAL, this);
		}
		coins -= 5;
	}
	else if (coins >= 10) {
		powerUp();
		coins -= 10;
	}
	for (auto const& observer : observers) {
		observer->notify(NOTIFICATION_PICK_COIN, &coins);
	}
}

void Player::powerUp() {
	int stat = rand() % 5;
	//stat = HEALTH_POINTS;		// Debug
	switch (stat) {
	case ATTACK_DAMAGE:
		if (attack < CAP_PLAYER_ATTACK)
			attack += 0.5;
		break;
	case HEALTH_POINTS:
		if (maxHp < CAP_PLAYER_HP)
			maxHp++;
		if (hp < maxHp)
			hp++;
		break;
	case SHOT_CADENCE:
		if (shotCadence > CAP_PLAYER_SHOT_CADENCE)
			shotCadence -= 2;
		break;
	case MOVEMENT_SPEED:
		if (speed < CAP_PLAYER_SPEED)
			speed += 0.5;
		break;
	case PROJECTILE_SIZE:
		if (shotSize < CAP_PLAYER_PROJECTILE_SIZE)
			shotSize++;
		break;
	}
	cout << "Player powered up" << endl;
	printPlayer();
	for (auto const& observer : observers) {
		observer->notify(NOTIFICATION_POWER_UP, this);
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
		for (auto const& observer : observers) {
			observer->notify(NOTIFICATION_PLAYER_SHOOT);
		}
		return new Projectile(PLAYER_PROJECTILE_FILE, 
			x, y, mouseX, mouseY, shotSize, shotSize, attack, game);
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

void Player::printPlayer() {
	cout << "---- Stats ----" << endl;
	cout << " HP: " << hp << "/" << maxHp << endl;
	cout << " Coins: " << coins << endl;
	cout << " Attack: " << attack << endl;
	cout << " Speed: " << speed << endl;
	cout << " Cadence: " << shotCadence << endl;
	cout << " Projectile: " << shotSize << endl;
	cout << "---------------" << endl;
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