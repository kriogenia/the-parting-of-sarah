#pragma once

#include <string>
using namespace std;

enum eObserverMessages {
	PLAYER_HIT
};

class Observer
{
public:
	Observer();

	void notify(string message);
};

