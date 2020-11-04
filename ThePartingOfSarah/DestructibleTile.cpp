#include "DestructibleTile.h"

DestructibleTile::DestructibleTile(string filename, int x, int y, int width, int hp, Game* game) :
	MappedTile(filename, x, y, width, hp, game) {
	this->hp = hp;
}

void DestructibleTile::triggerImpact() {
	this->hp--;
	this->position++;
}

bool DestructibleTile::isDestroyed() {
	return this->hp == 0;
}