#pragma once

#include "HealthBar.h"

constexpr auto HEART_WIDTH = 18;
constexpr auto HEART_HEIGHT = 15;

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