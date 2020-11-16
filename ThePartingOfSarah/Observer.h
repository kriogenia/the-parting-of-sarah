#pragma once

#include <string>
using namespace std;

enum eObserverMessages {
	NOTIFICATION_PLAYER_HIT,
	NOTIFICATION_PLAYER_HEAL,
	NOTIFICATION_PLAYER_SHOOT,
	NOTIFICATION_POWER_UP,
	NOTIFICATION_CLEAR_ROOM,
	NOTIFICATION_ENTER_ROOM,
	NOTIFICATION_PICK_COIN
};

/* interface */
class Observer
{
public:
	virtual void notify(eObserverMessages message, void* publisher = nullptr) = 0;
};