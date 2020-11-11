#include "Bee.h"

Bee::Bee(float x, float y, Room* room, Game* game) :
	Enemy("res/sprites/bird/Bee_Moving_Left.png", x, y, 36, 34, room->player, game) 
{
	this->flying = true;
	this->room = room;
	this->hp = BEE_HP;
	this->speed = BEE_SPEED;

	importAnimations();
	this->animation = movingAnimations[LEFT];
}

Bee::~Bee() {
	delete shootingAnimation;
}

void Bee::draw(int scrollX, int scrollY, float rotation) {
	// Calculate angle of the vector bee, player
	float dx = player->x - x;
	float dy = player->y - y;
	float angle = acos(-dy / sqrt(pow(dx, 2) + pow(dy, 2)));	// angle of the bee-player vector
	angle *= (180.0 / 3.14156);									// to grads
	angle = angle * (dx / abs(dx)) + 180;						// adaptation to sprite direciton
	animation->draw(x - scrollX, y - scrollY, angle);
}

void Bee::setOrientation() {}

void Bee::importAnimations() {
	shootingAnimation = new Animation("res/sprites/bee/Bee_Shooting.png",
		width, height, 288, 34, 2, 8, false, game);
	hitAnimations.clear();
	hitAnimations.insert_or_assign(LEFT, new Animation("res/sprites/bee/Bee_Hit.png",
		width, height, 180, 34, 2, 5, false, game));
	movingAnimations.clear();
	movingAnimations.insert_or_assign(LEFT, new Animation("res/sprites/bee/Bee_Moving.png",
		width, height, 216, 34, 4, 6, true, game));
}