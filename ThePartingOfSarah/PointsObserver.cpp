#include "PointsObserver.h"

PointsObserver::PointsObserver(int* points) :
	Observer()
{
	this->points = points;
}

void PointsObserver::notify(eObserverMessages message, void* publisher)
{
	switch (message) {
	case NOTIFICATION_PLAYER_HIT:
		*points -= 30;
		break;
	case NOTIFICATION_PLAYER_HEAL:
		*points += 15;
		break;
	case NOTIFICATION_POWER_UP:
		*points += 50;
		break;
	case NOTIFICATION_ENTER_NEW_FLOOR:
		*points += *(int*)publisher * 100;
		break;
	case NOTIFICATION_CLEAR_ROOM:
		*points += 5;
		break;
	case NOTIFICATION_BOSS_KILLED:
	case NOTIFICATION_ENEMY_KILLED:
		*points += ((Enemy*)publisher)->points;
		break;
	case NOTIFICATION_PICK_COIN:
		*points += 1;
		break;
	case NOTIFICATION_PICK_ITEM:
		*points += 50;
		break;
	}
}