#include "Litost.h"

Litost::Litost(float x, float y, Environment* room, Game* game) :
	Boss("res/sprites/litost/Litost_Moving.png", x, y, 64, 64, room, game)
{
	importAnimations();

	this->name = "Litost";
	this->subtitle = "He cooks";
	this->cooldown = DEFAULT_BOSS_CD;

	this->maxHp = LITOST_HP;
	this->hp = maxHp;
	this->speed = LITOST_SPEED;

	this->animation = movingAnimations[LEFT];
}

Litost::~Litost()
{
	delete shieldAnimation;
	delete shootConeAnimation;
	delete shootFromWallAnimation;
}

void Litost::damage(float damage)
{
	if (this->action != HIDING) {
		Boss::damage(damage);
	}
	else {
		for (auto const& observer : observers) {
			observer->notify(NOTIFICATION_BLOCKED_SHOT);
		}
	}
}

void Litost::importAnimations()
{
	dyingAnimation = new Animation("res/sprites/litost/Litost_Dying.png",
		width, height, 256, 64, 4, 4, false, game);
	movingAnimations.clear();
	movingAnimations.insert_or_assign(LEFT, new Animation("res/sprites/litost/Litost_Moving.png",
		width, height, 256, 64, 4, 4, true, game));
	shieldAnimation = new Animation("res/sprites/litost/Litost_Hiding.png",
		width, height, 256, 64, 8, 4, false, game);
	shootConeAnimation = new Animation("res/sprites/litost/Litost_Shooting_Cone.png",
		width, height, 256, 64, 4, 4, false, game);
	shootFromWallAnimation = new Animation("res/sprites/litost/Litost_Shooting_Wall.png",
		width, height, 256, 64, 4, 4, false, game);
}

void Litost::doAction()
{
	int actionIndex = rand() % DEFAULT_BOSS_ACTIONS;
	switch (actionIndex) {
	case SHIELD_UP:
		shieldUp();
		break;
	case SHOOT_CONE:
		shootCone();
		break;
	case SHOOT_FROM_WALLS:
		shootFromWalls();
		break;
	}
}

void Litost::shieldUp()
{
	this->animation = shieldAnimation;
	this->action = HIDING;
}

void Litost::shootCone()
{
	this->animation = shootConeAnimation;
	this->action = SHOOTING;
	room->addEnemyProjectile(new Projectile(LITOST_FISH_PROJECTILE_FILE, 
		x, y, room->player->x, room->player->y, 16, 12, game));
	room->addEnemyProjectile(new Projectile(LITOST_FISH_PROJECTILE_FILE,
		x, y, room->player->x, room->player->y + LITOST_SHOT_SPREAD, 16, 12, game));
	room->addEnemyProjectile(new Projectile(LITOST_FISH_PROJECTILE_FILE,
		x, y, room->player->x, room->player->y - LITOST_SHOT_SPREAD, 16, 12, game));
	room->addEnemyProjectile(new Projectile(LITOST_FISH_PROJECTILE_FILE,
		x, y, room->player->x, room->player->y + LITOST_SHOT_SPREAD * 2, 16, 12, game));
	room->addEnemyProjectile(new Projectile(LITOST_FISH_PROJECTILE_FILE,
		x, y, room->player->x, room->player->y - LITOST_SHOT_SPREAD * 2, 16, 12, game));
}

void Litost::shootFromWalls()
{
	this->animation = shootFromWallAnimation;
	this->action = SHOOTING;
	room->addEnemyProjectile(new Projectile(LITOST_FANG_PROJECTILE_FILE,
		x - 180, y - 180, x - 180, y + 180, 24, 8, game));
	room->addEnemyProjectile(new Projectile(LITOST_FANG_PROJECTILE_FILE,
		x + 180, y - 180, x - 180, y - 180, 24, 8, game));
	room->addEnemyProjectile(new Projectile(LITOST_FANG_PROJECTILE_FILE,
		x + 180, y + 180, x + 180, y - 180, 24, 8, game));
	room->addEnemyProjectile(new Projectile(LITOST_FANG_PROJECTILE_FILE,
		x - 180, y + 180, x + 180, y + 180, 24, 8, game));
}