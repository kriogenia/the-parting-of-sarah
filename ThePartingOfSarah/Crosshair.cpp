#include "Crosshair.h"

Crosshair::Crosshair(Game* game) :
	Actor("res/sprites/crosshair.png", 0, 0, 32, 32, 48, 48, game) 
{
	this->type = HUD;
}

void Crosshair::update(int mouseX, int mouseY) {
	this->x = mouseX;
	this->y = mouseY;
}