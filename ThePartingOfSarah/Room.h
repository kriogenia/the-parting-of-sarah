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

enum eTileType {
	NO_TILE = ' ',
	FLOOR = '.',
	TOP_LEFT_WALL = '/',
	TOP_RIGHT_WALL = '\\',
	BOTTOM_LEFT_WALL = '{',
	BOTTOM_RIGHT_WALL = '}',
	TOP_WALL = 'T',
	LEFT_WALL = 'L',
	RIGHT_WALL = 'R',
	BOTTOM_WALL = 'B',
	HORIZONTAL_DOOR = '-',
	VERTICAL_DOOR = '|'
};

class Room {
public:
	Room(eType type, int x, int y, int number, Game* game);
	~Room();

	void loadMap();

	void draw(int scrollX, int scrollY);
	bool hasPlayerInside(int playerX, int playerY);

	bool isNeighbour(Room* room);
	void append(Room* room);
	Room* expand(int code, int floorSize);

	void printGrid();

	eType type;
	int x;
	int y;
	int mapWidth = TILES_PER_ROOM * TILE_SIZE;

	Room* top = nullptr;
	Room* left = nullptr;
	Room* bottom = nullptr;
	Room* right = nullptr;

private:
	void loadMapObject(char character, int x, int y);

	void generateFloor();
	void generateWalls();
	void generateCorridors();
	void readFile();
	void generateTiles();

	Game* game;
	string filename;

	list<Tile*> tiles;
	list<Tile*> doors;
	char grid[TILES_PER_ROOM][TILES_PER_ROOM];
	
	int code = -1;

	int offsetRoomX;
	int offsetRoomY;
};

