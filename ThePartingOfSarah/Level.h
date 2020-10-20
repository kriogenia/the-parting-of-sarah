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
	~Level();

	Room* currentRoom;

private:
	void generateRooms();
	queue<int> getCodes();
	void setStartingRoom(queue<int> codes);
	void setBossRoom(queue<int> codes);
	void setTreasureRoom(queue<int> codes);
	void generateCommonRooms(queue<int> codes);
	void printFloor();

	list<Room*> rooms;
	Room* startingRoom;
	Room* bossRoom;
	Room* treasureRoom;
};

