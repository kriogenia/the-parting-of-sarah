#pragma once

#include "Game.h"

#include "DestructibleTile.h"
#include "Door.h"
#include "Enemy.h"
#include "MappedTile.h"
#include "Rock.h"
#include "Space.h"

#include "Pig.h"					// TODO delete

constexpr auto TILES_PER_ROOM = 30;
constexpr auto TILES_PER_FILE = 24;
constexpr auto FLOOR_OFFSET = 3*TILE_SIZE;

enum eRoomType {
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
	VERTICAL_DOOR = '|',
	ROCK = 'X',
	POND_TOP = 'P',
	POND_BASE = '~',
	BARREL = 'M',
	SPAWN = 'S'
};

class Room {
public:
	Room(eRoomType type, int x, int y, int number, Space* space, Actor* player, Game* game);
	~Room();

	void loadMap();

	void draw(int scrollX, int scrollY);
	void update();

	bool hasPlayerInside();
	void playerEntered();
	void setCleared();
	void openDoors();
	void closeDoors();

	bool isNeighbour(Room* room);
	void append(Room* room);
	Room* expand(int code, int floorSize);

	void printGrid();

	eRoomType type;
	int x;
	int y;
	int mapWidth = TILES_PER_ROOM * TILE_SIZE;

	Room* top = nullptr;
	Room* left = nullptr;
	Room* bottom = nullptr;
	Room* right = nullptr;

	list<DestructibleTile*> destructibles;
	list<Enemy*> enemies;

private:
	void loadMapObject(char character, int x, int y);

	void generateWalls();
	void generateCorridors();
	void readFile();
	void generateTiles();

	Game* game;
	Actor* player;
	Space* space;
	string filename;

	list<Tile*> tiles;
	list<Door*> doors;
	char grid[TILES_PER_ROOM][TILES_PER_ROOM];

	list<Enemy*> enemiesToSpawn;
	
	int code = -1;
	bool cleared = false;

	int offsetRoomX;
	int offsetRoomY;
};

