#pragma once

#include "Projectile.h"

/* interface */
class Environment
{
public:
	virtual void addEnemyProjectile(Projectile* projectile) = 0;
	virtual void spawnCoin(float x, float y) = 0;

	Actor* player;
};