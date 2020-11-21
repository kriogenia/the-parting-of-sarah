#include "Hud.h"

Hud::Hud(Game* game) :
	game(game)
{
	coins = new CoinDisplay(game);
	crosshair = new Crosshair(game);
	health = new HealthDisplay(game);
	map = new MapDisplay(game);
	text = new TextDisplay(game);
}

Hud::~Hud() {
	delete coins;
	delete crosshair;
	delete health;
	delete map;
	delete text;
}

void Hud::draw() {
	crosshair->draw();
	coins->draw();
	health->draw();
	map->draw();
	text->draw();
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

void Hud::updateText(string message) {
	text->update(message);
}