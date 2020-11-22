#include "Boss.h"

Boss::Boss(string filename, float x, float y, int width, int height, Environment* room, Game* game) :
	Enemy(filename, x, y, width, height, room, game)
{
}

Boss::~Boss()
{
	// delete list of actions
}

void Boss::setAction(bool endAction)
{
	// swap actions
}

void Boss::death()
{
	this->action = DYING;
	this->animation = dyingAnimation;
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
