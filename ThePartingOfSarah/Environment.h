#pragma once

#include "Character.h"
#include "Projectile.h"
#include "Tile.h"

/* interface */
class Environment
{
public:
	/* Game cycle */
	virtual void update() = 0;
	/* Environment interactions */
	virtual void addEnemy(Character* enemy) = 0;
	virtual void addEnemyProjectile(Projectile* projectile) = 0;
	virtual void addTile(Tile* tile) = 0;
	virtual void spawnCoin(float x, float y) = 0;
	virtual void spawnItem(float x, float y) = 0;
	virtual void spawnStair() {};
	/* Player pointer */
	Actor* player;
};