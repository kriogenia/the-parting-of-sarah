#pragma once

#include <queue>
#include "Background.h"
#include "Game.h"
#include "BossRoom.h"

constexpr auto FLOOR_SIZE = 5;
constexpr auto FLOORS_POOL_SIZE = 25;

using namespace std;

class Level {
public:
	Level(int floor, Space* space, Actor* player, Game* game);
	~Level();
	/* Game cycle */
	void draw(int scrollX, int scrollY);
	void update();
	/* Screen update */
	void moveScroll(int* scrollX, int* scrollY);
	/* Observers */
	void expandObservers();
	list<Observer*> observers;
	/* Key room pointers */
	BossRoom* bossRoom;
	Room* currentRoom;

private:
	/* Level generation */
	void generateRooms();
	queue<int> getCodes();
	void setStartingRoom(queue<int>* codes);
	void setBossRoom(queue<int>* codes);
	void setTreasureRoom(queue<int>* codes);
	void generateCommonRooms(queue<int> codes);
	void loadRoomMaps();
	/* Debug */
	void printFloor();
	/* Modules */
	Game* game;
	Space* space;
	/* Room pointers */
	list<Room*> rooms;
	Room* startingRoom;
	Room* treasureRoom;
	/* Actors */
	Actor* player;
	Background* background;
};

