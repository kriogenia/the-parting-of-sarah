#pragma once

#include <queue>
#include "Background.h"
#include "Game.h"
#include "Room.h"

constexpr auto FLOOR_SIZE = 5;
constexpr auto FLOORS_POOL_SIZE = 25;

using namespace std;

class Level {
public:
	Level(int floor, Game* game);
	~Level();

	void draw(int scrollX, int scrollY);

	Room* currentRoom;

private:
	void generateRooms();
	queue<int> getCodes();
	void setStartingRoom(queue<int> codes);
	void setBossRoom(queue<int> codes);
	void setTreasureRoom(queue<int> codes);
	void generateCommonRooms(queue<int> codes);
	void printFloor();

	Game* game;

	list<Room*> rooms;
	Room* startingRoom;
	Room* bossRoom;
	Room* treasureRoom;

	Background* background;
};

