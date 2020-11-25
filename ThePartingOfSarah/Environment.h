#pragma once

#include "Projectile.h"

/* interface */
class Environment
{
public:
	virtual void addEnemyProjectile(Projectile* projectile) = 0;
	virtual void spawnCoin(float x, float y) = 0;
	virtual void spawnItem(float x, float y) = 0;
	virtual void spawnStair() {};

	virtual void update() = 0;

	Actor* player;
};