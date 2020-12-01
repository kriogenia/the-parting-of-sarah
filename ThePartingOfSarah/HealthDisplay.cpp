#include "HealthDisplay.h"

HealthDisplay::HealthDisplay(Game* game)
{
	baseHealth = new HealthBar("res/hud/health_empty.png", 10, 10, 3 * HEART_WIDTH, HEART_HEIGHT, game);
	currentHealth = new HealthBar("res/hud/health_full.png", 10, 10, 3 * HEART_WIDTH, HEART_HEIGHT, game);
}

void HealthDisplay::draw() {
	baseHealth->draw();
	currentHealth->draw();
}

void HealthDisplay::update(int currentHp, int maxHp) {
	baseHealth->currentWidth = maxHp * HEART_WIDTH;
	currentHealth->currentWidth = currentHp * HEART_WIDTH;
}