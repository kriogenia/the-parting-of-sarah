#include "Level.h"

Level::Level(int floor, Space* space, Game* game) :
	space(space),
	game(game) 
{
	cout << "Floor: " << floor << endl;
	background = new Background(game);
	generateRooms();
	currentRoom = startingRoom;
	currentRoom->openDoors();
	currentRoom->printGrid();
}

Level::~Level() {
	rooms.clear();
	delete startingRoom;
	delete bossRoom;
	delete treasureRoom;
	delete background;
}

void Level::draw(int scrollX, int scrollY) {
	background->draw();
	for (auto const& room : rooms) {
		room->draw(scrollX, scrollY);
	}
}

void Level::update(int playerX, int playerY) {
	background->update();
	// Out of room player, check if they entered a new room
	if (currentRoom == nullptr) {
		for (auto const& room : rooms) {
			if (room->hasPlayerInside(playerX, playerY)) {
				currentRoom = room;
				currentRoom->playerEntered();
			}
		}
		return;
	}
	// Check if player is still in room
	if (currentRoom->hasPlayerInside(playerX, playerY)) {
		return;
	}
	// Otherwise it exited
	currentRoom = nullptr;
}

void Level::calculateScroll(int playerX, int playerY, int* scrollX, int* scrollY) {
	if (currentRoom != nullptr) {
		int roomDimension = TILES_PER_ROOM * TILE_SIZE;
		*scrollX = currentRoom->x * roomDimension + roomDimension / 2 - HEIGHT / 2;
		*scrollY = currentRoom->y * roomDimension + roomDimension / 2 - WIDTH / 2;
	}
	else {
		*scrollX = playerX - HEIGHT / 2;
		*scrollY = playerY - WIDTH / 2;
	}
}

void Level::generateRooms() {
	queue<int> codes = getCodes();
	setStartingRoom(&codes);
	setBossRoom(&codes);
	setTreasureRoom(&codes);
	generateCommonRooms(codes);
	loadRoomMaps();
	printFloor();
}

queue<int> Level::getCodes() {
	// Randomize the codes and push them to a queue
	queue<int> codes;
	vector<int> codesList;
	for (int i = 0; i < FLOORS_POOL_SIZE; i++) {
		codesList.push_back(i);
	}
	while (!codesList.empty()) {
		int next = rand() % codesList.size();
		codes.push(codesList[next]);
		codesList.erase(codesList.begin() + next);
	}
	return codes;
}

void Level::setStartingRoom(queue<int>* codes) {
	// Generate the Starting Room (center of the grid)
	startingRoom = new Room(STARTING_ROOM, FLOOR_SIZE / 2, FLOOR_SIZE / 2, (*codes).front(), space, game);
	rooms.push_back(startingRoom);
	(*codes).pop();
}

void Level::setBossRoom(queue<int>* codes) {
	// Generate the Boss Room (outer ring)
	int bossRoomX = ((rand() % 4) / 2) * 4;
	int bossRoomY = ((rand() % 4) % 2) * 4;
	bossRoom = new Room(BOSS_ROOM, bossRoomX, bossRoomY, (*codes).front(), space, game);
	rooms.push_back(bossRoom);
	(*codes).pop();
}

void Level::setTreasureRoom(queue<int>* codes) {
	// Generate a Treasure Room (far from the boss room)
	int treasureRoomPlacement = rand() % (FLOOR_SIZE - 2) ^ 2 - 1;
	int fromI = (bossRoom->x == 0) ? 2 : 0;
	int toI = (bossRoom->x == FLOOR_SIZE - 1) ? FLOOR_SIZE - 2 : FLOOR_SIZE;
	int fromJ = (bossRoom->y == 0) ? 2 : 0;
	int toJ = (bossRoom->y == FLOOR_SIZE - 1) ? FLOOR_SIZE - 2 : FLOOR_SIZE;
	for (int i = fromI; i < toI; i++) {
		for (int j = fromJ; j < toJ; j++) {
			if (i != j) {
				if (treasureRoomPlacement == 0) {
					treasureRoom = new Room(TREASURE_ROOM, i, j, (*codes).front(), space, game);
					rooms.push_back(treasureRoom);
					(*codes).pop();
					return;
				}
				treasureRoomPlacement--;
			}
		}
	}
}

void Level::generateCommonRooms(queue<int> codes) {
	// Generates the room graph and connects the rooms
	bool connectedBossRoom = false;
	bool connectedTreasureRoom = false;
	Room* node = startingRoom;
	queue<Room*> expandableRooms;
	expandableRooms.push(startingRoom);
	// Generate rooms until boss and treasure room are connected with the start
	while (true) {
		// Check for neighbour boss or treasure room if not yet connected
		if (!connectedBossRoom) {
			if (node->isNeighbour(bossRoom)) {
				connectedBossRoom = true;
			}
		}
		if (!connectedTreasureRoom) {
			if (node->isNeighbour(treasureRoom)) {
				connectedTreasureRoom = true;
			}
		}
		// Connect the rooms if they are neighbours
		for (auto const& room : rooms) {
			if (node->isNeighbour(room)) {
				node->append(room);
			}
		}
		// When both are connected, it exits
		if (connectedBossRoom && connectedTreasureRoom) {
			return;
		}
		// Get a new node to iterate from the children of the current one
		Room* nextNode = node->expand(codes.front(), FLOOR_SIZE);
		if (nextNode != nullptr) {
			rooms.push_back(nextNode);
			expandableRooms.push(nextNode);
			node = nextNode;
			codes.pop();
		}
		// Or a previous visited node if there's no viable children
		else {
			node = expandableRooms.front();
			expandableRooms.pop();
		}
	}
}

void Level::loadRoomMaps() {
	for (auto const& room : rooms) {
		room->loadMap();
	}
}

void Level::printFloor() {
	string grid[FLOOR_SIZE][FLOOR_SIZE];
	for (int i = 0; i < FLOOR_SIZE; i++) {
		for (int j = 0; j < FLOOR_SIZE; j++) {
			grid[i][j] = ".";
		}
	}
	for (auto const& room : rooms) {
		grid[room->x][room->y] = room->type;
	}
	cout << "\nLevel grid:" << endl;
	for (int i = 0; i < FLOOR_SIZE; i++) {
		for (int j = 0; j < FLOOR_SIZE; j++) {
			cout << grid[j][i] << " ";
		}
		cout << endl;
	}
}