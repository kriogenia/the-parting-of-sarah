#include "Projectile.h"

Projectile::Projectile(string filename, int x, int y, int mouseX, int mouseY, int size, Game* game) :
	Actor(filename, x, y, size, size, game)
{
	this->type = PROJECTILE;

	float vectorLength = sqrt(pow(mouseX - x, 2) + pow(mouseY - y, 2));
	this->vx = (mouseX - x) / vectorLength * PROJECTILE_SPEED;
	this->vy = (mouseY - y) / vectorLength * PROJECTILE_SPEED;
}

void Projectile::draw(float scrollX, float scrollY) {
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

	//float angle = vx * 1

	SDL_RenderCopyEx(game->renderer,
		texture, &source, &destination, 0, NULL, SDL_FLIP_NONE);
}

void Projectile::collisionedWith(Actor* actor) {
	this->destructionFlag = true;
}