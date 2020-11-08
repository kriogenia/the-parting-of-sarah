#include "Projectile.h"

Projectile::Projectile(string filename, int x, int y, int mouseX, int mouseY, int size, Game* game) :
	Actor(filename, x, y, size, size, game)
{
	this->type = PROJECTILE;

	float vectorLength = sqrt(pow(mouseX - x, 2) + pow(mouseY - y, 2));
	this->vx = (mouseX - x) / vectorLength * PROJECTILE_SPEED;
	this->vy = (mouseY - y) / vectorLength * PROJECTILE_SPEED;
}

void Projectile::draw(int scrollX, int scrollY) {
	SDL_Rect source;
	source.x = 0;
	source.y = 0;
	source.w = fileWidth;	// texture.width;
	source.h = fileHeight;	// texture.height;

	SDL_Rect destination;
	destination.x = x - width / 2 - scrollX;
	destination.y = y - height / 2 - scrollY;
	destination.w = width;
	destination.h = height;

	// Calculate angle of the shot to rotate the texture
	float angle = acos(-vy / sqrt(pow(vx, 2) + pow(vy, 2))) * 180.0 / 3.14156 + 90;

	SDL_RenderCopyEx(game->renderer,
		texture, &source, &destination, angle, NULL, SDL_FLIP_NONE);
}

void Projectile::collisionedWith(Actor* actor) {
	this->destructionFlag = true;
}