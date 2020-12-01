#include "Bee.h"

Bee::Bee(float x, float y, Environment* room, Game* game) :
	Enemy("res/sprites/bird/Bee_Moving_Left.png", x, y, 36, 34, room, game) 
{
	importAnimations();

	this->flying = true;
	this->points = BEE_POINTS;
	this->hp = BEE_HP;
	this->speed = BEE_SPEED;
	this->shotTime = BEE_SHOT_CADENCE;

	this->animation = movingAnimations[LEFT];
}

Bee::~Bee() {
	delete shootingAnimation;
}

void Bee::draw(int scrollX, int scrollY, float rotation) {
	// Calculate angle of the vector bee, player
	float dx = room->player->x - x;
	float dy = room->player->y - y;
	float angle = acos(-dy / sqrt(pow(dx, 2) + pow(dy, 2)));	// angle of the bee-player vector
	angle *= (180.0 / 3.14156);									// to grads
	angle = angle * (dx / abs(dx)) + 180;						// adaptation to sprite direciton
	animation->draw(x - scrollX, y - scrollY, angle);
}

void Bee::update() {
	shotTime--;
	if (this->action == SHOOTING &&
		this->animation->currentFrame == BEE_SHOT_FRAME)
		shoot();
	Enemy::update();
}

/* Shoots the projectile */
void Bee::shoot() {
	Projectile* projectile = new Projectile(BEE_PROJECTILE_FILE, x, y, room->player->x, room->player->y, 8, 8, game);
	room->addEnemyProjectile(projectile);
}

void Bee::setMovement() {
	if (this->action == SHOOTING) {
		vx = 0;
		vy = 0;
	}
	else {
		Enemy::setMovement();
	}
}

void Bee::setAction(bool endAction) {
	float distance = sqrt(pow(room->player->x - x, 2) + pow(room->player->y - y, 2));
	if (this->action == MOVING && distance < BEE_LOCK_DISTANCE && shotTime < 0) {
		this->action = SHOOTING;
		this->animation = shootingAnimation;
		this->shotTime = BEE_SHOT_CADENCE;
	}
	Enemy::setAction(endAction);
}

void Bee::importAnimations() {
	dyingAnimation = new Animation("res/sprites/bee/Bee_Dying.png",
		width, height, 180, 34, 2, 5, false, game);
	hitAnimations.clear();
	hitAnimations.insert_or_assign(LEFT, new Animation("res/sprites/bee/Bee_Hit.png",
		width, height, 180, 34, 2, 5, false, game));
	movingAnimations.clear();
	movingAnimations.insert_or_assign(LEFT, new Animation("res/sprites/bee/Bee_Moving.png",
		width, height, 216, 34, 2, 6, true, game));
	shootingAnimation = new Animation("res/sprites/bee/Bee_Shooting.png",
		width, height, 288, 34, 0, 8, false, game);
}