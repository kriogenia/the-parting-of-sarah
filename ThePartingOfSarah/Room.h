#pragma once

#include "Game.h"
#include "MappedTile.h"

constexpr auto TILES_PER_ROOM = 30;
constexpr auto TILES_PER_FILE = 24;
constexpr auto FLOOR_OFFSET = 3*TILE_SIZE;

enum eType {
	NO_ROOM,
	COMMON_ROOM,
	STARTING_ROOM,
	TREASURE_ROOM,
	BOSS_ROOM
};

class Room {
public:
	Room(eType type, int x, int y, int number, Game* game);
	~Room();

	void draw(int scrollX, int scrollY);
	bool hasPlayerInside(int playerX, int playerY);

	bool isNeighbour(Room* room);
	void append(Room* room);
	Room* expand(int code, int floorSize);

	eType type;
	int x;
	int y;
	int mapWidth = TILES_PER_ROOM * TILE_SIZE;

	Room* top = nullptr;
	Room* left = nullptr;
	Room* bottom = nullptr;
	Room* right = nullptr;

private:
	void loadMap();
	void loadMapObject(char character, float x, float y);
	void generateWalls();

	Game* game;
	list<Tile*> tiles;
	string filename;
	
	int code = -1;
};

