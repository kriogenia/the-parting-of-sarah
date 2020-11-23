#include "MapDisplay.h"

MapDisplay::MapDisplay(Game* game) :
	game(game)
{
	init();
}

MapDisplay::~MapDisplay() {
	tiles.clear();
}

void MapDisplay::init() {
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			grid[i][j] = NO_ROOM;
		}
	}
	currentX = MAP_SIZE / 2;
	currentY = MAP_SIZE / 2;
	grid[currentX][currentY] = STARTING_ROOM;
	regenerateTiles();
}

void MapDisplay::draw() {
	for (auto const& tile : tiles) {
		tile->draw();
	}
}

void MapDisplay::update(Room* room) {
	// Set room
	grid[room->y][room->x] = room->type;
	currentX = room->x;
	currentY = room->y;
	// Create unknown rooms
	if (room->top != nullptr && grid[room->y - 1][room->x] == NO_ROOM)
		grid[room->y - 1][room->x] = UNKNOWN_ROOM;
	if (room->left != nullptr && grid[room->y][room->x - 1] == NO_ROOM)
		grid[room->y][room->x - 1] = UNKNOWN_ROOM;
	if (room->bottom != nullptr && grid[room->y + 1][room->x] == NO_ROOM)
		grid[room->y + 1][room->x] = UNKNOWN_ROOM;
	if (room->right != nullptr && grid[room->y][room->x + 1] == NO_ROOM)
		grid[room->y][room->x + 1] = UNKNOWN_ROOM;
	// Update the list of tiles
	regenerateTiles();
}

void MapDisplay::regenerateTiles() {
	tiles.clear();
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			if (grid[i][j] != NO_ROOM) {
				tiles.push_back(
					new MappedTile("res/hud/map_tiles.png", 
						WIDTH - 15 - (5-j) * MAP_TILE_SIZE, 15 + i * MAP_TILE_SIZE,
						MAP_TILE_SIZE, MAP_TILE_SIZE, 120, MAP_TILE_SIZE, 
						grid[i][j], game));
			}
		}
	}
	tiles.push_back(
		new MappedTile("res/hud/map_tiles.png",
			WIDTH - 15 - (5 - currentX) * MAP_TILE_SIZE, 15 + currentY * MAP_TILE_SIZE,
			MAP_TILE_SIZE, MAP_TILE_SIZE, 120, MAP_TILE_SIZE,
			CURRENT_ROOM_TILE, game));
}