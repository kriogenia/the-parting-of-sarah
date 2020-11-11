#pragma once

#include "Game.h"

#include "Character.h"
#include "DestructibleTile.h"
#include "Door.h"
#include "MappedTile.h"
#include "Projectile.h"
#include "Rock.h"
#include "Space.h"

#include "EnemyFactory.h"
class EnemyFactory;

constexpr auto TILES_PER_ROOM = 30;
constexpr auto TILES_PER_FILE = 24;
constexpr auto FLOOR_OFFSET = 3*TILE_SIZE;

/* Types of rooms */
enum eRoomType {
	NO_ROOM,
	COMMON_ROOM,
	STARTING_ROOM,
	TREASURE_ROOM,
	BOSS_ROOM
};

class Room {
public:
	Room(eRoomType type, int x, int y, int number, Space* space, Actor* player, Game* game);
	~Room();
	/* Room layout loading */
	void loadMap();

	void draw(int scrollX, int scrollY);
	void update();
	/* Game flow */
	bool hasPlayerInside();
	void playerEntered();
	void setCleared();
	void openDoors();
	void closeDoors();
	/* Level generation */
	bool isNeighbour(Room* room);
	void append(Room* room);
	Room* expand(int code, int floorSize);
	/* Debug */
	void printGrid();
	/* Room attributes */
	eRoomType type;
	int x;
	int y;
	int mapWidth = TILES_PER_ROOM * TILE_SIZE;
	/* Room neighbours */
	Room* top = nullptr;
	Room* left = nullptr;
	Room* bottom = nullptr;
	Room* right = nullptr;

	Actor* player;

private:
	/* Tile creation */
	void loadMapObject(char character, int x, int y);
	/* Room generation */
	void generateWalls();
	void generateCorridors();
	void readFile();
	void generateTiles();

	EnemyFactory* spawner;
	Game* game;
	Space* space;
	/* Room generators */
	string filename;
	char grid[TILES_PER_ROOM][TILES_PER_ROOM];
	/* Room tiles */
	list<Tile*> tiles;
	list<Door*> doors;
	list<DestructibleTile*> destructibles;
	/* Room actors */
	list<Character*> enemies;
	list<Character*> enemiesToSpawn;
	list<Projectile*> enemyProjectiles;
	/* Room attributes */
	int code = -1;
	bool cleared = false;
	/* Room global position*/
	int offsetRoomX;
	int offsetRoomY;
};

