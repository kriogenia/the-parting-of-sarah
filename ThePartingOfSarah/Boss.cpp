#include "Boss.h"

Boss::Boss(string filename, float x, float y, int width, int height, Environment* room, Game* game) :
	Enemy(filename, x, y, width, height, room, game)
{
}

void Boss::update()
{
	cooldown--;
	Character::update();
}

void Boss::setAction(bool endAction)
{
	if (this->action != MOVING && !endAction)
		return;
	if (cooldown <= 0) {
		cooldown = DEFAULT_BOSS_CD;
		doAction();
	}
	else {
		this->action = MOVING;
	}
}

void Boss::death()
{
	this->action = DYING;
	this->animation = dyingAnimation;
	this->room->spawnStair();
	for (auto const& observer : observers) {
		observer->notify(NOTIFICATION_BOSS_KILLED, this);
	}
}

void Boss::hit()
{
	for (auto const& observer : observers) {
		observer->notify(NOTIFICATION_BOSS_HIT, this);
	}
}
