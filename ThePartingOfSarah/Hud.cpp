#include "Hud.h"

Hud::Hud(Game* game) :
	game(game)
{
	boss = new BossHealthDisplay(game);
	coins = new CoinDisplay(game);
	crosshair = new Crosshair(game);
	health = new HealthDisplay(game);
	map = new MapDisplay(game);
	pause = new PauseDisplay(game);
	text = new TextDisplay(game);
}

Hud::~Hud() {
	delete boss;
	delete coins;
	delete crosshair;
	delete health;
	delete map;
	delete text;
}

void Hud::draw(bool isPaused) {
	boss->draw();
	coins->draw();
	health->draw();
	map->draw();
	text->draw();
	crosshair->draw();
	if (isPaused) {
		pause->draw();
	}
}

void Hud::updateBossHealthDisplay(int currentHp, int maxHp) {
	boss->show = (currentHp <= 0) ? false : true;
	boss->update(currentHp, maxHp);
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

void Hud::updateStats(Player* player)
{
	pause->update(player);
}

void Hud::updateText(string message, string submessage) {
	text->update(message, submessage);
}

void Hud::resetMap() {
	map->init();
}