#include "Projectile.h"

Projectile::Projectile(string filename, int x, int y, int mouseX, int mouseY, int size, Game* game) :
	Actor(filename, x, y, size, size, game)
{
	this->type = PROJECTILE;

	float vectorLength = sqrt(pow(mouseX - x, 2) + pow(mouseY - y, 2));
	this->vx = (mouseX - x) / vectorLength * PROJECTILE_SPEED;
	this->vy = (mouseY - y) / vectorLength * PROJECTILE_SPEED;
}

void Projectile::draw(int scrollX, int scrollY, float rotation) {
	// Calculate angle of the shot to rotate the sprite
	float angle = acos(-vy / sqrt(pow(vx, 2) + pow(vy, 2)));	// angle of the shot
	angle *= (180.0 / 3.14156);									// to grads
	angle = angle * (vx / abs(vx)) + 90;						// adaptation to sprite direciton
	Actor::draw(scrollX, scrollY, angle);
}

void Projectile::collisionedWith(Actor* actor) {
	if (actor->type == ENEMY || actor->type == TILE)
		this->destructionFlag = true;
}