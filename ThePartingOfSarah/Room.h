#pragma once

#include <vector>
using namespace std;

enum eType {
	NO_ROOM,
	COMMON_ROOM,
	STARTING_ROOM,
	TREASURE_ROOM,
	BOSS_ROOM
};

class Room {
public:
	Room(eType type, int x, int y, int number = -1);
	~Room();

	bool isNeighbour(Room* room);
	void append(Room* room);
	Room* expand(int code, int floorSize);

	eType type;
	int x;
	int y;

	Room* top = nullptr;
	Room* left = nullptr;
	Room* bottom = nullptr;
	Room* right = nullptr;

private:
	int code;
};

