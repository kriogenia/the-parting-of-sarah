#include "Room.h"

Room::Room(eType type, int x, int y, int number, Game* game) :
	type(type),
	x(x),
	y(y),
	code(number),
	game(game) {
	this->filename = "res/rooms/room_2.txt";	// <- Code / type
	loadMap();
}

Room::~Room() {
	tiles.clear();
}

void Room::draw(int scrollX, int scrollY) {
	for (auto const& tile : tiles) {
		tile->draw(scrollX, scrollY);
	}
}

bool Room::hasPlayerInside(int playerX, int playerY) {
	int topLimit = this->y * TILES_PER_ROOM * TILE_SIZE + FLOOR_OFFSET;
	int leftLimit = this->x * TILES_PER_ROOM * TILE_SIZE + FLOOR_OFFSET;
	int rightLimit = (this->x + 1) * TILES_PER_ROOM * TILE_SIZE - FLOOR_OFFSET;
	int bottomLimit = (this->y + 1) * TILES_PER_ROOM * TILE_SIZE - FLOOR_OFFSET;
	if (playerX > leftLimit && playerX < rightLimit && playerY > topLimit && playerY < bottomLimit) {
		return true;
	}
	return false;
}

void Room::loadMap() {
	char character;
	string line;
	int offsetRoomX = this->x * TILES_PER_ROOM * TILE_SIZE;
	int offsetRoomY = this->y * TILES_PER_ROOM * TILE_SIZE;
	ifstream streamFile(filename.c_str());
	// Floor mapping
	for (int i = 0; i < TILES_PER_FILE; i++) {
		for (int j = 0; j < TILES_PER_FILE; j++) {
			tiles.push_back(new MappedTile("res/tiles/floor.png",
				j * TILE_SIZE + offsetRoomX + FLOOR_OFFSET + TILE_SIZE / 2, 
				i * TILE_SIZE + offsetRoomY + FLOOR_OFFSET + TILE_SIZE / 2,
				160, rand() % 10, game));
		}
	}
	if (!streamFile.is_open()) {
		cout << "Error loading file " << filename << endl;
		return;
	}
	else {
		// For each line
		for (int i = 0; getline(streamFile, line); i++) {
			istringstream streamLine(line);
			// For each character in the line
			for (int j = 0; !streamLine.eof(); j++) {
				streamLine >> character;			// Read character 
				int x = j * TILE_SIZE + offsetRoomX + FLOOR_OFFSET;	
				int y = i * TILE_SIZE + offsetRoomY + FLOOR_OFFSET;
				loadMapObject(character, x, y);
			}
		}
	}
	streamFile.close();
	generateWalls();
}

void Room::loadMapObject(char character, float x, float y) {
	Tile* tile = nullptr;
	switch (character) {
	case 'B': {
		//tile = new Tile("res/tiles/room_base.png", x+48, y+48, 96, 96, game);
		break;
	}
	case 'x': {
		//tile = new Tile("res/floor.png", x, y, game);
		break;
	}
	case '~': {
		//tile = new Tile("res/water.png", x, y, game);
		break;
	}
	}
	if (tile != nullptr) {
		//tiles.push_back(tile);
	}
}

void Room::generateWalls() {
	int offsetRoomX = this->x * TILES_PER_ROOM * TILE_SIZE;
	int offsetRoomY = this->y * TILES_PER_ROOM * TILE_SIZE;
	// Corners
	tiles.push_back(new MappedTile("res/tiles/wall.png",
		offsetRoomX + TILE_SIZE * 2 + TILE_SIZE / 2,
		offsetRoomY + TILE_SIZE * 2 + TILE_SIZE / 2,
		160, 0, game));
	tiles.push_back(new MappedTile("res/tiles/wall.png",
		offsetRoomX + TILE_SIZE * 2 + TILE_SIZE / 2,
		offsetRoomY + TILES_PER_ROOM * TILE_SIZE - (TILE_SIZE * 2 + TILE_SIZE / 2),
		160, 1, game));
	tiles.push_back(new MappedTile("res/tiles/wall.png",
		offsetRoomX + TILES_PER_ROOM * TILE_SIZE - (TILE_SIZE * 2 + TILE_SIZE / 2),
		offsetRoomY + TILES_PER_ROOM * TILE_SIZE - (TILE_SIZE * 2 + TILE_SIZE / 2),
		160, 2, game));
	tiles.push_back(new MappedTile("res/tiles/wall.png",
		offsetRoomX + TILES_PER_ROOM * TILE_SIZE - (TILE_SIZE * 2 + TILE_SIZE / 2),
		offsetRoomY + TILE_SIZE * 2 + TILE_SIZE / 2,
		160, 3, game));
	// Sides
	for (int i = 3; i < TILES_PER_ROOM - 3; i++) {
		// TOP
		tiles.push_back(new MappedTile("res/tiles/wall.png",
			offsetRoomX + TILE_SIZE * i + TILE_SIZE / 2,
			offsetRoomY + TILE_SIZE * 2 + TILE_SIZE / 2,
			160, 4 + rand() % 2, game));
		// LEFT
		tiles.push_back(new MappedTile("res/tiles/wall.png",
			offsetRoomX + TILE_SIZE * 2 + TILE_SIZE / 2,
			offsetRoomY + TILE_SIZE * i + TILE_SIZE / 2,
			160, 6 + i % 2, game));
		// RIGHT
		tiles.push_back(new MappedTile("res/tiles/wall.png",
			offsetRoomX + TILES_PER_ROOM * TILE_SIZE - (TILE_SIZE * 2 + TILE_SIZE / 2),
			offsetRoomY + TILES_PER_ROOM * TILE_SIZE - (TILE_SIZE * i + TILE_SIZE / 2),
			160, 8 + i % 2, game));
		// BOT
		tiles.push_back(new MappedTile("res/tiles/wall.png",
			offsetRoomX + TILES_PER_ROOM * TILE_SIZE - (TILE_SIZE * i + TILE_SIZE / 2),
			offsetRoomY + TILES_PER_ROOM * TILE_SIZE - (TILE_SIZE * 2 + TILE_SIZE / 2),
			160, 10 + rand() % 2, game));
	}
}



bool Room::isNeighbour(Room* room) {
	if (this->x == room->x) {
		return (this->y == room->y-1 || this->y == room->y+1);
	}
	else if (this->y == room->y) {
		return (this->x == room->x - 1 || this->x == room->x + 1);
	}
	return false;
}

void Room::append(Room* room) {
	if (this->x == room->x) {
		if (this->y < room->y) {
			bottom = room;
			room->top = this;
		}
		else {
			top = room;
			room->bottom = this;
		}
	}
	else {
		if (this->x < room->x) {
			right = room;
			room->left = this;
		}
		else {
			left = room;
			room->right = this;
		}
	}
}

Room* Room::expand(int childCode, int floorSize) {
	struct position {
		int x;
		int y;
	};
	// Select all the possible children
	vector<position> possibleChildren;
	if (y != 0 && this->top == nullptr) {
		possibleChildren.push_back({ this->x, this->y - 1});
	}
	if (y != floorSize - 1 && this->bottom == nullptr) {
		possibleChildren.push_back({ this->x, this->y + 1 });
	}
	if (x != 0 && this->left == nullptr) {
		possibleChildren.push_back({ this->x - 1, this->y });
	}
	if (x != floorSize - 1 && this->right == nullptr) {
		possibleChildren.push_back({ this->x + 1, this->y });
	}
	// Generate a random child among the possible ways
	if (!possibleChildren.empty()) {
		position newRoomXY = possibleChildren[code % possibleChildren.size()];
		return new Room(COMMON_ROOM, newRoomXY.x, newRoomXY.y, childCode, game);
	}
	return nullptr;
}