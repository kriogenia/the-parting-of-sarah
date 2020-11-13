#pragma once

#include <string>
using namespace std;

enum eObserverMessages {
	NOTIFICATION_PLAYER_HIT,
	NOTIFICATION_PLAYER_SHOT,
	NOTIFICATION_DOOR_OPEN,
	NOTIFICATION_DOOR_CLOSE
};

class Observer
{
public:
	Observer();

	virtual void notify(eObserverMessages message, void* publisher = nullptr) = 0;
};