#include "Crosshair.h"

Crosshair::Crosshair(Game* game) :
	Actor("res/sprites/crosshair.png", 0, 0, 48, 48, 256, 256, game) {

}

void Crosshair::update(int mouseX, int mouseY) {
	this->x = mouseX;
	this->y = mouseY;
}