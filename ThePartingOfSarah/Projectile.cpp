#include "Projectile.h"

Projectile::Projectile(string filename, int x, int y, int destinyX, int destinyY, int size, bool playerShot, Game* game) :
	Actor(filename, x, y, size, size, game)
{
	if (playerShot) {
		this->type = PROJECTILE;
		this->speed = PLAYER_PROJECTILE_SPEED;
	}
	else {
		this->type = ENEMY_PROJECTILE;
		this->speed = ENEMY_PROJECTILE_SPEED;
	}

	float vectorLength = sqrt(pow(destinyX - x, 2) + pow(destinyY - y, 2));
	this->vx = (destinyX - x) / vectorLength * PLAYER_PROJECTILE_SPEED;
	this->vy = (destinyY - y) / vectorLength * PLAYER_PROJECTILE_SPEED;
}

void Projectile::draw(int scrollX, int scrollY, float rotation) {
	// Calculate angle of the shot to rotate the sprite
	float angle = acos(-vy / sqrt(pow(vx, 2) + pow(vy, 2)));	// angle of the shot
	angle *= (180.0 / 3.14156);									// to grads
	angle = angle * (vx / abs(vx)) + 90;						// adaptation to sprite direciton
	Actor::draw(scrollX, scrollY, angle);
}

void Projectile::collisionedWith(Actor* actor) {
	if (actor->type == TILE ||
		(type == PROJECTILE && actor->type == ENEMY) ||
		(type == ENEMY_PROJECTILE && actor->type == PLAYER))
		this->destructionFlag = true;
}