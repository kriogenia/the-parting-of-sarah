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
}

void Boss::hit()
{
	// notify observer
}
