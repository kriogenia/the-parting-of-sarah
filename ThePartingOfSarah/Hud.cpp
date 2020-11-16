#include "Hud.h"

Hud::Hud(Game* game) :
	game(game)
{
	coins = new CoinDisplay(game);
	crosshair = new Crosshair(game);
	health = new HealthDisplay(game);
	map = new MapDisplay(game);
}

Hud::~Hud() {
	delete coins;
	delete crosshair;
	delete health;
	delete map;
}

void Hud::draw() {
	crosshair->draw();
	coins->draw();
	health->draw();
	map->draw();
}

void Hud::updateCoins(int currentCoins) {
	coins->update(currentCoins);
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
