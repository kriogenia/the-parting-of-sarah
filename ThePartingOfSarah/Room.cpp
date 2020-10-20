#include "Room.h"

Room::Room(eType type, int x, int y, int number) :
	type(type),
	x(x),
	y(y) {
	if (number != -1) {
		code = number;
	}
}

Room::~Room() {
	delete top;
	delete left;
	delete bottom;
	delete right;
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
			right = room;
			room->left = this;
		}
		else {
			left = room;
			room->right = this;
		}
	}
	else {
		if (this->x < room->x) {
			bottom = room;
			room->top = this;
		}
		else {
			top = room;
			room->bottom = this;
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
	if (x != 0 && this->top == nullptr) {
		possibleChildren.push_back({ this->x - 1, this->y});
	}
	if (x != floorSize - 1 && this->bottom == nullptr) {
		possibleChildren.push_back({ this->x + 1, this->y });
	}
	if (y != 0 && this->left == nullptr) {
		possibleChildren.push_back({ this->x, this->y - 1 });
	}
	if (y != floorSize - 1 && this->right == nullptr) {
		possibleChildren.push_back({ this->x, this->y + 1 });
	}
	// Generate a random child among the possible ways
	if (!possibleChildren.empty()) {
		position newRoomXY = possibleChildren[code % possibleChildren.size()];
		return new Room(COMMON_ROOM, newRoomXY.x, newRoomXY.y, childCode);
	}
	return nullptr;
}


// return "nombrearchivo_" + type + code <- si es common