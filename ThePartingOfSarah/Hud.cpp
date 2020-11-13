#include "Hud.h"

Hud::Hud(Game* game) :
	game(game)
{
	delete crosshair;
	crosshair = new Crosshair(game);
	delete health;
	health = new HealthDisplay(game);
}

Hud::~Hud() {
	delete crosshair;
	delete health;
}

void Hud::draw() {
	crosshair->draw();
	health->draw();
}

void Hud::updateCrosshair(int mouseX, int mouseY) {
	crosshair->update(mouseX, mouseY);
}

void Hud::updateHealthDisplay(int currentHp, int maxHp) {
	health->update(currentHp, maxHp);
}