#include "Door.h"

Door::Door(string filename, int x, int y, int width, int height, int fileWidth, int fileHeight, Game* game) :
	MappedTile(filename, x, y, width, height, fileWidth, fileHeight, DOOR_OPEN, game) {
}

void Door::open() {
	this->position = 1;
}

void Door::close() {
	this->position = 0;
}