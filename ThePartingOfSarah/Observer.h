#pragma once

#include <string>
using namespace std;

enum eObserverMessages {
	NOTIFICATION_PLAYER_HIT,
	NOTIFICATION_PLAYER_SHOT,
	NOTIFICATION_CLEAR_ROOM,
	NOTIFICATION_ENTER_ROOM
};

class Observer
{
public:
	Observer();

	virtual void notify(eObserverMessages message, void* publisher = nullptr) = 0;
};