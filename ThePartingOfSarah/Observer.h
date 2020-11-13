#pragma once

#include <string>
using namespace std;

enum eObserverMessages {
	NOTIFICATION_PLAYER_HIT
};

class Observer
{
public:
	Observer();

	virtual void notify(eObserverMessages message);
};