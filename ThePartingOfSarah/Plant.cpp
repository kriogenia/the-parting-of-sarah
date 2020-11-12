#include "Plant.h"

Plant::Plant(float x, float y, Room* room, Game* game) :
	Enemy("res/sprites/plant/Plant_Moving_Left.png", x, y, 42, 42, room->player, game) {

	this->room = room;
	this->hp = PLANT_HP;
	this->speed = PLANT_SPEED;
	this->shotTime = PLANT_SHOT_CADENCE;
	this->vx = PLANT_SPEED;
	this->vy = PLANT_SPEED;

	importAnimations();
	this->animation = movingAnimations[LEFT];
}

void Plant::update() {
	shotTime--;
	if (this->action == SHOOTING &&
		this->animation->currentFrame == PLANT_SHOT_FRAME)
		shoot();
	Enemy::update();
}

void Plant::shoot() {
	Projectile* projectile = new Projectile(PLANT_PROJECTILE_FILE, x, y, player->x, player->y, 8, false, game);
	room->addEnemyProjectile(projectile);
}

void Plant::setMovement() {}

void Plant::setAction(bool endAction) {
	if (this->action == MOVING && shotTime < 0) {
		this->action = SHOOTING;
		this->animation = shootingAnimations[orientation];
		this->shotTime = PLANT_SHOT_CADENCE;
	}
	Enemy::setAction(endAction);
}

void Plant::importAnimations() {
	dyingAnimation = new Animation("res/sprites/plant/Plant_Dying.png",
		width, height, 220, 42, 0, 5, false, game);
	hitAnimations.clear();
	hitAnimations.insert_or_assign(LEFT, new Animation("res/sprites/plant/Plant_Hit_Left.png",
		width, height, 220, 42, 2, 5, false, game));
	hitAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/plant/Plant_Hit_Right.png",
		width, height, 220, 42, 2, 5, false, game));
	movingAnimations.clear();
	movingAnimations.insert_or_assign(LEFT, new Animation("res/sprites/plant/Plant_Moving_Left.png",
		width, height, 484, 42, 4, 11, true, game));
	movingAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/plant/Plant_Moving_Right.png",
		width, height, 484, 42, 4, 11, true, game));
	shootingAnimations.clear();
	shootingAnimations.insert_or_assign(LEFT, new Animation("res/sprites/plant/Plant_Shooting_Left.png",
		width, height, 352, 42, 2, 8, false, game));
	shootingAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/plant/Plant_Shooting_Right.png",
		width, height, 352, 42, 2, 8, false, game));
}