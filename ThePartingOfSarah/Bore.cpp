#include "Bore.h"

Bore::Bore(float x, float y, Environment* room, Game* game) :
	Boss("res/sprites/bore/Bore_Moving.png", x, y, 64, 64, room, game)
{
	importAnimations();

	this->name = "Bore";
	this->subtitle = "and Franky";
	this->cooldown = DEFAULT_BOSS_CD;

	this->maxHp = BORE_HP;
	this->hp = maxHp;
	this->speed = BORE_SPEED;

	this->animation = movingAnimations[LEFT];
}

Bore::~Bore()
{
	delete shootAnimation;
	delete sleepAnimation;
	delete summonFrankyAnimation;
}

void Bore::update()
{
	if (this->action == SHOOTING) {
		if (this->animation->currentFrame == 3) {
			room->addEnemyProjectile(new ChasingProjectile(x, y, room->player, game));
		}
	}
	Boss::update();
}

void Bore::importAnimations()
{
	dyingAnimation = new Animation("res/sprites/bore/Bore_Dying.png",
		width, height, 256, 64, 4, 4, false, game);
	movingAnimations.clear();
	movingAnimations.insert_or_assign(LEFT, new Animation("res/sprites/bore/Bore_Moving.png",
		width, height, 256, 64, 4, 4, true, game));
	shootAnimation = new Animation("res/sprites/bore/Bore_Shooting.png",
		width, height, 256, 64, 4, 4, false, game);
	sleepAnimation = new Animation("res/sprites/bore/Bore_Sleeping.png",
		width, height, 256, 64, 4, 4, false, game);
	summonFrankyAnimation = new Animation("res/sprites/bore/Bore_Summoning.png",
		width, height, 256, 64, 4, 4, false, game);
}

void Bore::doAction()
{
	int actionIndex = rand() % DEFAULT_BOSS_ACTIONS;
	switch (actionIndex) {
	case SHOOT:
		shoot();
		break;
	case SLEEP:
		sleep();
		break;
	case SUMMON_FRANKY:
		summonFranky();
		break;
	}
}

void Bore::shoot()
{
	this->animation = shootAnimation;
	this->action = SHOOTING;
}

void Bore::sleep()
{
	this->animation = sleepAnimation;
	this->action = HIDING;
	// Healing
	hp += BORE_HEALING;
	if (hp > maxHp) {
		hp = maxHp;
	}
	for (auto const& observer : observers) {
		observer->notify(NOTIFICATION_BOSS_HEAL, this);
	}
}

void Bore::summonFranky()
{
	this->animation = summonFrankyAnimation;
	this->action = SHOOTING;
	room->addEnemy(new Franky(x, y, room, game));
}


/****************
    * FRANKY *
****************/

Bore::Franky::Franky(float x, float y, Environment* room, Game* game) :
	Enemy("res/sprites/franky/Franky_Moving_Left.png", x, y, 24, 24, room, game)
{
	importAnimations();

	this->flying = true;
	this->hp = FRANKY_HP;
	this->speed = FRANKY_SPEED;

	this->animation = movingAnimations[LEFT];
}

void Bore::Franky::importAnimations()
{
	dyingAnimation = new Animation("res/sprites/franky/Franky_Dying.png",
		width, height, 48, 24, 2, 2, false, game);
	hitAnimations.clear();
	hitAnimations.insert_or_assign(LEFT, new Animation("res/sprites/franky/Franky_Hit_Left.png",
		width, height, 48, 24, 2, 2, false, game));
	hitAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/franky/Franky_Hit_Right.png",
		width, height, 48, 24, 2, 2, false, game));
	movingAnimations.clear();
	movingAnimations.insert_or_assign(LEFT, new Animation("res/sprites/franky/Franky_Moving_Left.png",
		width, height, 48, 24, 2, 2, true, game));
	movingAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/franky/Franky_Moving_Right.png",
		width, height, 48, 24, 2, 2, true, game));
}

void Bore::Franky::death()
{
	this->action = DYING;
	this->animation = dyingAnimation;
	// doesn't drop coins
}

/*********************
* CHASING PROJECTILE *
*********************/

Bore::ChasingProjectile::ChasingProjectile(float x, float y, Actor* player, Game* game) :
	Projectile("res/sprites/bore/Bore_Projectile.png", x, y, x, y - 100,
		BORE_PROJECTILE_SIZE, BORE_PROJECTILE_SIZE, game)
{
	this->player = player;
	this->speed = BORE_PROJECTILE_SPEED;
	this->aliveTime = BORE_PROJECTILE_LIFE;
	update();
}

void Bore::ChasingProjectile::draw(int scrollX, int scrollY, float rotation)
{
	update();
	Projectile::draw(scrollX, scrollY, rotation);
}

void Bore::ChasingProjectile::update()
{
	aliveTime--;
	if (aliveTime <= 0) {
		this->destructionFlag = true;
	}
	float vectorLength = sqrt(pow(player->x - x, 2) + pow(player->y - y, 2));
	this->vx = (player->x - x) / vectorLength * speed;
	this->vy = (player->y - y) / vectorLength * speed;
}