#include "BossHealthDisplay.h"

BossHealthDisplay::BossHealthDisplay(Game* game) :
	HealthDisplay(game)
{
	baseHealth = new HealthBar("res/hud/boss_health_empty.png", WIDTH / 2 - 100, HEIGHT - 50, 200, 41, game);
	currentHealth = new HealthBar("res/hud/boss_health_full.png", WIDTH / 2 - 100, HEIGHT - 50, 200, 41, game);
	this->show = false;
}

void BossHealthDisplay::draw() {
	if (show)	HealthDisplay::draw();
}

void BossHealthDisplay::update(int currentHp, int maxHp) {
	float remaining = (float) currentHp / (float) maxHp;
	currentHealth->currentWidth = remaining * (currentHealth->width - 14) + 7;
}