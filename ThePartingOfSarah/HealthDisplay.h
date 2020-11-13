#pragma once

#include "HealthBar.h"

class HealthDisplay
{
public:
	HealthDisplay(Game* game);

	void draw();
	void update(int currentHp, int maxHp);

private:
	HealthBar* baseHealth;
	HealthBar* currentHealth;
	Game* game;
};