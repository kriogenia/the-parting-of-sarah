#include "Hud.h"

Hud::Hud(Game* game) :
	game(game)
{
	crosshair = new Crosshair(game);
	health = new HealthDisplay(game);
	map = new MapDisplay(game);
}

Hud::~Hud() {
	delete crosshair;
	delete health;
	delete map;
}

void Hud::draw() {
	crosshair->draw();
	health->draw();
	map->draw();
}

void Hud::updateCrosshair(int mouseX, int mouseY) {
	crosshair->update(mouseX, mouseY);
}

void Hud::updateHealthDisplay(int currentHp, int maxHp) {
	health->update(currentHp, maxHp);
}

void Hud::updateMap(Room* room) {
	map->update(room);
}
