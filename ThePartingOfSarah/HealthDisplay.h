#pragma once

#include "HealthBar.h"

constexpr auto HEART_WIDTH = 18;
constexpr auto HEART_HEIGHT = 15;

class HealthDisplay
{
public:
	HealthDisplay(Game* game);

	virtual void draw();
	virtual void update(int currentHp, int maxHp);

protected:
	HealthBar* baseHealth;
	HealthBar* currentHealth;
};