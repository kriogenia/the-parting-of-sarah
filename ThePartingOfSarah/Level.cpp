#include "Level.h"

Level::Level(int floor)  {
	cout << "Floor: " << floor << endl;
	generateRooms();
	currentRoom = startingRoom;
}

Level::~Level() {
	rooms.clear();
	delete startingRoom;
	delete bossRoom;
	delete treasureRoom;
}

void Level::generateRooms() {
	queue<int> codes = getCodes();
	setStartingRoom(codes);
	setBossRoom(codes);
	setTreasureRoom(codes);
	generateCommonRooms(codes);
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

void Level::setStartingRoom(queue<int> codes) {
	// Generate the Starting Room (center of the grid)
	startingRoom = new Room(STARTING_ROOM, FLOOR_SIZE / 2, FLOOR_SIZE / 2, codes.front());
	rooms.push_back(startingRoom);
	codes.pop();
}

void Level::setBossRoom(queue<int> codes) {
	// Generate the Boss Room (outer ring)
	int bossRoomX = ((rand() % 4) / 2) * 4;
	int bossRoomY = ((rand() % 4) % 2) * 4;
	bossRoom = new Room(BOSS_ROOM, bossRoomX, bossRoomY, codes.front());
	rooms.push_back(bossRoom);
	codes.pop();
}

void Level::setTreasureRoom(queue<int> codes) {
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
					treasureRoom = new Room(TREASURE_ROOM, i, j, codes.front());
					rooms.push_back(treasureRoom);
					codes.pop();
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
	for (int i = 0; i < FLOOR_SIZE; i++) {
		string line = "";
		for (int j = 0; j < FLOOR_SIZE; j++) {
			line += grid[i][j] + " ";
		}
		cout << line << endl;
	}
}