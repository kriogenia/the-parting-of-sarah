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

	void draw();
	void update(Room* room);

private:
	void regenerateTiles();

	int grid[MAP_SIZE][MAP_SIZE];
	list<Actor*> tiles;

	Game* game;

	int currentX;
	int currentY;
};

