#pragma once

#include "Game.h"

#include "Character.h"
#include "DestructibleTile.h"
#include "Door.h"
#include "Environment.h"
#include "ItemFactory.h"
#include "Space.h"

#include "EnemyFactory.h"
class EnemyFactory;

/* Size */
constexpr auto TILES_PER_ROOM = 30;
constexpr auto TILES_PER_FILE = 24;
constexpr auto FLOOR_OFFSET = 3*TILE_SIZE;

/* Types of rooms */
enum eRoomType {
	UNKNOWN_ROOM,
	COMMON_ROOM,
	STARTING_ROOM,
	TREASURE_ROOM,
	BOSS_ROOM,
	NO_ROOM
};

class Room :
	public Environment
{
public:
	Room(eRoomType type, int x, int y, int number, Space* space, Actor* player, Game* game);
	~Room();
	/* Game cycle */
	void draw(int scrollX, int scrollY);
	void update() override;
	/* Room layout loading */
	void loadMap();
	/* Game flow */
	bool hasPlayerInside();
	virtual void playerEntered();
	void setCleared();
	void openDoors();
	void closeDoors();
	/* Environment */
	void addEnemy(Character* projectile) override;
	void addEnemyProjectile(Projectile* enemy) override;
	void addTile(Tile* tile) override;
	void spawnCoin(float x, float y) override;
	void spawnItem(float x, float y) override;
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
	bool cleared = false;
	/* Room neighbours */
	Room* top = nullptr;
	Room* left = nullptr;
	Room* bottom = nullptr;
	Room* right = nullptr;
	/* Observers */
	list<Observer*> observers;

protected:
	/* Tile creation */
	void loadMapObject(char character, int x, int y);
	/* Room generation */
	void generateWalls();
	void generateCorridors();
	void readFile();
	void generateTiles();

	EnemyFactory* spawner;
	ItemFactory* dropper;
	Game* game;
	Space* space;
	/* Room generators */
	string filename;
	char grid[TILES_PER_ROOM][TILES_PER_ROOM];
	/* Tiles */
	list<Tile*> tiles;
	list<Door*> doors;
	list<Tile*> destructibles;
	/* Actors */
	list<Character*> enemies;
	list<Character*> enemiesToSpawn;
	list<Item*> items;
	list<Projectile*> enemyProjectiles;
	/* attributes */
	int code = -1;
	/* Global position*/
	int offsetRoomX;
	int offsetRoomY;
};

