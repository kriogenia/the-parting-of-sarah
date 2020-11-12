#include "Hud.h"

Hud::Hud(Game* game) :
	game(game)
{
	delete crosshair;
	crosshair = new Crosshair(game);
}

Hud::~Hud() {
	delete crosshair;
}

void Hud::draw() {
	crosshair->draw();
}

void Hud::update(int mouseX, int mouseY) {
	crosshair->update(mouseX, mouseY);
}