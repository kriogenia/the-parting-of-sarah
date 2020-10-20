#include "Level.h"

Level::Level(int floor)  {
	cout << "Floor: " << floor << endl;
	generateRooms();
}

void Level::generateRooms() {
	// Randomize the codes
	vector<int> codesList;
	for (int i = 0; i < FLOORS_POOL_SIZE; i++) {
		codesList.push_back(i);
	}
	queue<int> codes;
	while (!codesList.empty()) {
		int next = rand() % codesList.size();
		codes.push(codesList[next]);
		codesList.erase(codesList.begin() + next);
	}
	int grid[FLOOR_SIZE][FLOOR_SIZE];
	// Create the empty grid with the starting floor
	for (int i = 0; i < FLOOR_SIZE; i++) {
		for (int j = 0; j < FLOOR_SIZE; j++) {
			grid[i][j] = NO_ROOM;
			// create an store starting room
		}
	}
	grid[FLOOR_SIZE / 2][FLOOR_SIZE / 2] = STARTING_ROOM;
	startingRoom = new Room(STARTING_ROOM, FLOOR_SIZE / 2, FLOOR_SIZE / 2, codes.front());
	rooms.push_back(startingRoom);
	codes.pop();
	// Generate a Boss Room (outer ring)
	int bossRoomX = ((rand() % 4) / 2) * 4;
	int bossRoomY = ((rand() % 4) % 2) * 4;
	bossRoom = new Room(BOSS_ROOM, bossRoomX, bossRoomY, codes.front());
	rooms.push_back(bossRoom);
	codes.pop();
	grid[bossRoomX][bossRoomY] = BOSS_ROOM;
	// Generate a Treasure Room (far from the boss room)
	int treasureRoomPlacement = rand() % (FLOOR_SIZE - 2)^2 - 1;
	int fromI = (bossRoomX == 0) ? 2 : 0;
	int toI = (bossRoomX == FLOOR_SIZE - 1) ? FLOOR_SIZE - 2 : FLOOR_SIZE;
	int fromJ = (bossRoomY == 0) ? 2 : 0;
	int toJ = (bossRoomY == FLOOR_SIZE - 1) ? FLOOR_SIZE - 2 : FLOOR_SIZE;
	for (int i = fromI; i < toI; i++) {
		for (int j = fromJ; j < toJ; j++) {
			if (i != j) {
				if (treasureRoomPlacement == 0) {
					grid[i][j] = TREASURE_ROOM;
					treasureRoom = new Room(TREASURE_ROOM, i, j, codes.front());
					rooms.push_back(treasureRoom);
					codes.pop();
					goto generateCommonRooms;
				}
				treasureRoomPlacement--;
			}
		}
	}
	// Generates the room graph and connects the rooms
	generateCommonRooms:
	bool connectedBossRoom = false;
	bool connectedTreasureRoom = false;
	Room* node = startingRoom;
	queue<Room*> expandableRooms;
	expandableRooms.push(startingRoom);
	while (!connectedBossRoom || !connectedTreasureRoom) {
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
		if (connectedBossRoom && connectedTreasureRoom) {
			break;
		}
		// Get a new node to iterate
		Room* nextNode = node->expand(codes.front(), FLOOR_SIZE);
		if (nextNode != nullptr) {
			rooms.push_back(nextNode);
			expandableRooms.push(nextNode);
			node = nextNode;
			codes.pop();
		}
		else {
			node = expandableRooms.front();
			expandableRooms.pop();
		}
	}


	for (auto const& room: rooms) {
		cout << room->type << " [" << room->x << "," << room->y << "]" << endl;
	}
}