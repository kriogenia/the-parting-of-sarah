#pragma once

#include "Room.h"

constexpr auto MAP_TILE_SIZE = 20;
constexpr auto MAP_SIZE = 5;
constexpr auto CURRENT_ROOM_TILE = 5;

class MapDisplay
{
public:
	MapDisplay(Game* game);
	~MapDisplay();
	/* Game cycle */
	void init();
	void draw();
	void update(Room* room);

private:
	/* Map update */
	void regenerateTiles();
	/* Map */
	int grid[MAP_SIZE][MAP_SIZE];
	list<Actor*> tiles;
	/* Placer current position */
	int currentX;
	int currentY;

	Game* game;
};

