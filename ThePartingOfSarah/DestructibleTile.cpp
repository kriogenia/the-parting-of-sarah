#include "DestructibleTile.h"

DestructibleTile::DestructibleTile(string filename, int x, int y, int width, int hp, Game* game) :
	MappedTile(filename, x, y, width, hp, game) {
	this->type = DESTRUCTIBLE_TILE;
	this->hp = hp;
}

void DestructibleTile::collisionedWith(Actor* actor) {
	if (actor->type == PROJECTILE || actor->type == ENEMY_PROJECTILE) {
		this->hp--;
		this->position = hp;
		if (hp <= 0) {
			this->destructionFlag = true;
		}
	}
}