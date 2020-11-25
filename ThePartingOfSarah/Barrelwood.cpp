#include "Barrelwood.h"

Barrelwood::Barrelwood(float x, float y, Environment* room, Game* game) :
	Boss("res/sprites/barrelwood/Barrelwood_Moving.png", x, y, 64, 64, room, game)
{
	importAnimations();
	
	this->name = "Barrelwood";
	this->subtitle = "The edge of Buttowski";
	this->cooldown = DEFAULT_BOSS_CD;

	this->maxHp = BARRELWOOD_HP;
	this->hp = maxHp;
	this->speed = BARRELWOOD_SPEED;
	this->flying = true;

	this->animation = movingAnimations[LEFT];
}

Barrelwood::~Barrelwood()
{
	delete rollXAnimation;
	delete rollYAnimation;
	delete smokeAnimation;
	delete spreadAnimation;
}

void Barrelwood::setMovement()
{
	if (this->action != RUNNING) {
		this->vx = 0;
		this->vy = 0;
	}
	else {
		this->vx = speed * directionX;
		this->vy = speed * directionY;
	}
}

void Barrelwood::importAnimations()
{
	dyingAnimation = new Animation("res/sprites/barrelwood/Barrelwood_Dying.png",
		width, height, 256, 64, 4, 4, false, game);
	movingAnimations.clear();
	movingAnimations.insert_or_assign(LEFT, new Animation("res/sprites/barrelwood/Barrelwood_Moving.png",
		width, height, 256, 64, 4, 4, true, game));
	rollXAnimation = new Animation("res/sprites/barrelwood/Barrelwood_Rolling_X.png",
		width, height, 256, 64, 4, 4, false, game);
	rollYAnimation = new Animation("res/sprites/barrelwood/Barrelwood_Rolling_Y.png",
		width, height, 256, 64, 4, 4, false, game);
	spreadAnimation = new Animation("res/sprites/barrelwood/Barrelwood_Spreading.png",
		width, height, 256, 64, 4, 4, false, game);
	smokeAnimation = new Animation("res/sprites/barrelwood/Barrelwood_Smoking.png",
		width, height, 256, 64, 4, 4, false, game);
}

void Barrelwood::doAction()
{
	int actionIndex = rand() % DEFAULT_BOSS_ACTIONS;
	actionIndex = SMOKING;			// Debug
	switch (actionIndex) {
	case SPREADING_ACID:
		spreadAcid();
		break;
	case ROLLING:
		roll();
		break;
	case SMOKING:
		smoke();
		break;
	}
}

void Barrelwood::spreadAcid()
{
	this->animation = spreadAnimation;
	this->action = SHOOTING;
	room->addTile(new AcidTile(x, y, game));
}

void Barrelwood::roll()
{
	this->action = RUNNING;
	int direction = rand() % 4;
	if (direction / 2 == 0) {
		directionX = (direction % 2 == 0) ? 1 : -1;
		directionY = 0;
		this->animation = rollXAnimation;
	}
	else {
		directionX = 0;
		directionY = (direction % 2 == 0) ? 1 : -1;
		this->animation = rollYAnimation;
	}
}

void Barrelwood::smoke()
{
	this->animation = smokeAnimation;
	this->action = SHOOTING;
	room->addEnemyProjectile(new SmokeProjectile(x, y, game));
	room->addEnemyProjectile(new SmokeProjectile(x + 10, y - 20, game));
	room->addEnemyProjectile(new SmokeProjectile(x + 30, y - 10, game));
	room->addEnemyProjectile(new SmokeProjectile(x - 15, y - 25, game));
	room->addEnemyProjectile(new SmokeProjectile(x - 25, y - 40, game));
}

/* Acid tile */

Barrelwood::AcidTile::AcidTile(float x, float y, Game* game) :
	Tile("res/sprites/barrelwood/acid.png", x, y, 128, 128, game)
{
	this->time = 60;
}

void Barrelwood::AcidTile::draw(int scrollX, int scrollY, float rotation)
{
	time--;
	if (time <= 0) {
		this->destructionFlag = true;
	}
	Tile::draw(scrollX, scrollY, rotation);
}

void Barrelwood::AcidTile::collisionedWith(Actor* actor)
{
	if (actor->type == PLAYER) {
		((Player*)actor)->damage();
	}
}

/* Smoke projectile */

Barrelwood::SmokeProjectile::SmokeProjectile(float x, float y, Game* game) :
	Projectile("res/sprites/barrelwood/Barrelwood_Projectile.png", x, y, x, y - 100,
		BARRELWOOD_PROJECTILE_SIZE, BARRELWOOD_PROJECTILE_SIZE, game)
{
	this->animation = new Animation("res/sprites/barrelwood/Barrelwood_Projectile.png",
		BARRELWOOD_PROJECTILE_SIZE, BARRELWOOD_PROJECTILE_SIZE, 65, 13, 2, 5, true, game);
}

void Barrelwood::SmokeProjectile::draw(int scrollX, int scrollY, float rotation)
{
	this->animation->update();
	this->animation->draw(x - scrollX, y - scrollY);
}
