#pragma once

#include "HealthBar.h"

constexpr auto HEART_WIDTH = 18;
constexpr auto HEART_HEIGHT = 15;

class HealthDisplay
{
public:
	HealthDisplay(Game* game);
	~HealthDisplay();
	/* Game cycle */
	virtual void draw();
	virtual void update(int currentHp, int maxHp);

protected:
	/* Components */
	HealthBar* baseHealth;
	HealthBar* currentHealth;
};