#pragma once

#include <queue>
#include "Game.h"
#include "Room.h"

#define FLOOR_SIZE 5
#define FLOORS_POOL_SIZE 25

using namespace std;

class Level {
public:
	Level(int floor);

private:
	void generateRooms();

	list<Room*> rooms;
	Room* startingRoom;
	Room* bossRoom;
	Room* treasureRoom;
};

