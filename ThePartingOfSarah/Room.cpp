#include "Room.h"

Room::Room(eRoomType type, int x, int y, int number, Space* space, Actor* player, Game* game) :
	type(type),
	x(x),
	y(y),
	code(number),
	space(space),
	game(game),
	spawner(EnemyFactory::getInstance())
{
	this->filename = "res/rooms/room_" + to_string(code) + ".txt";
	//this->filename = "res/rooms/room_21.txt";			// Debug
	this->offsetRoomX = this->x * TILES_PER_ROOM * TILE_SIZE;
	this->offsetRoomY = this->y * TILES_PER_ROOM * TILE_SIZE;
	this->player = player;
	// Grid initialization
	for (int i = 0; i < TILES_PER_ROOM; i++) {
		for (int j = 0; j < TILES_PER_ROOM; j++) {
			grid[i][j] = NO_TILE;
		}
	}
	/* Set not fighting rooms as cleared */
	if (type == STARTING_ROOM || type == TREASURE_ROOM) {
		cleared = true;
	}
}

Room::~Room() {
	coins.clear();
	destructibles.clear();
	doors.clear();
	enemies.clear();
	enemiesToSpawn.clear();
	enemyProjectiles.clear();
	tiles.clear();
}

void Room::draw(int scrollX, int scrollY) {
	for (auto const& tile : tiles)					tile->draw(scrollX, scrollY);
	for (auto const& tile : destructibles)			tile->draw(scrollX, scrollY);
	for (auto const& tile : doors)					tile->draw(scrollX, scrollY);
	for (auto const& coin : coins)					coin->draw(scrollX, scrollY);
	for (auto const& enemy : enemies)				enemy->draw(scrollX, scrollY);
	for (auto const& projectile : enemyProjectiles)	projectile->draw(scrollX, scrollY);
}

void Room::update() {
	// Enemies update
	list<Character*> enemiesToDelete;
	for (auto const& enemy : enemies) {
		enemy->update();
		if (enemy->destructionFlag) {
			enemiesToDelete.push_back(enemy);
		}
	}
	for (auto const& enemy : enemiesToDelete) {
		enemy->flying ? 
			space->removeFlyingDynamicActor(enemy) :
			space->removeDynamicActor(enemy);
		enemies.remove(enemy);
	}
	if (!cleared && enemies.empty() && enemiesToSpawn.empty()) {
		setCleared();
	}
	// Deletion of coins
	list<Coin*> coinsToDelete;
	for (auto const& coin : coins) {
		if (coin->destructionFlag) {
			coinsToDelete.push_back(coin);
		}
	}
	for (auto const& coin : coinsToDelete) {
		space->removeVirtualActor(coin);
		coins.remove(coin);
	}
	// Deletion of projectiles
	list<Projectile*> projectilesToDelete;
	for (auto const& projectile : enemyProjectiles) {
		if (projectile->destructionFlag) {
			projectilesToDelete.push_back(projectile);
		}
	}
	for (auto const& projectile : projectilesToDelete) {
		space->removeFlyingDynamicActor(projectile);
		enemyProjectiles.remove(projectile);
	}
	// Deletion of destructibles
	list<DestructibleTile*> destructiblesToDelete;
	for (auto const& destructible : destructibles) {
		if (destructible->destructionFlag) {
			destructiblesToDelete.push_back(destructible);
		}
	}
	for (auto const& destructible : destructiblesToDelete) {
		space->removeStaticActor(destructible);
		destructibles.remove(destructible);
	}
}

bool Room::hasPlayerInside() {
	int topLimit = offsetRoomY + FLOOR_OFFSET;
	int leftLimit = offsetRoomX + FLOOR_OFFSET;
	int rightLimit = offsetRoomX + TILES_PER_ROOM * TILE_SIZE - FLOOR_OFFSET;
	int bottomLimit = offsetRoomY + TILES_PER_ROOM * TILE_SIZE - FLOOR_OFFSET;
	if (player->x + player->width / 2 >= leftLimit &&
		player->x - player->width / 2 <= rightLimit &&
		player->y - player->height / 2 >= topLimit &&
		player->y + player->height / 2 <= bottomLimit) {
		return true;
	}
	return false;
}

void Room::playerEntered() {
	if (!cleared) {
		this->closeDoors();
		// Spawn enemies
		for (auto const& enemy : enemiesToSpawn) {
			enemies.push_back(enemy);
			(enemy->flying) ? 
				space->addFlyingDynamicActor(enemy) :
				space->addDynamicActor(enemy);
		}
		enemiesToSpawn.clear();
	}
	for (auto const& observer : observers) {
		observer->notify(NOTIFICATION_ENTER_ROOM, this);
	}
}

void Room::setCleared() {
	cleared = true;
	openDoors();
	for (auto const& observer : observers) {
		observer->notify(NOTIFICATION_CLEAR_ROOM);
	}
}

void Room::openDoors() {
	for (auto const& door : doors) {
		door->open();
		space->removeStaticActor(door);
	}
}

void Room::closeDoors() {
	for (auto const& door : doors) {
		door->close();
		space->addStaticActor(door);
	}
}

void Room::addEnemyProjectile(Projectile* projectile) {
	enemyProjectiles.push_back(projectile);
	space->addFlyingDynamicActor(projectile);
}

void Room::spawnCoin(float x, float y) {
	Coin* coin = new Coin(x, y, game);
	coins.push_back(coin);
	space->addVirtualActor(coin);
}

void Room::loadMap() {
	readFile();
	generateWalls();
	generateCorridors();
	generateTiles();
}

void Room::readFile() {
	char character;
	string line;
	ifstream streamFile(filename.c_str());
	if (!streamFile.is_open()) {
		cout << "Error loading file " << filename << endl;
		return;
	}
	else {
		// For each line
		for (int i = 0; getline(streamFile, line); i++) {
			istringstream streamLine(line);
			// For each character in the line
			for (int j = 0; j < TILES_PER_FILE; j++) {
				streamLine >> character;			// Read character 
				grid[j+3][i+3] = character;
			}
		}
	}
	streamFile.close();
}

void Room::generateWalls() {
	// Corners
	grid[2][2] = TOP_LEFT_WALL;
	grid[27][2] = TOP_RIGHT_WALL;
	grid[2][27] = BOTTOM_LEFT_WALL;
	grid[27][27] = BOTTOM_RIGHT_WALL;
	// Sides
	for (int i = 3; i < 14; i++) {
		// TOP
		grid[i][2] = TOP_WALL;
		grid[i+13][2] = TOP_WALL;
		// LEFT
		grid[2][i] = LEFT_WALL;
		grid[2][i+13] = LEFT_WALL;
		// RIGHT
		grid[27][i] = RIGHT_WALL;
		grid[27][i+13] = RIGHT_WALL;
		// BOT
		grid[i][27] = BOTTOM_WALL;
		grid[i+13][27] = BOTTOM_WALL;
	}
}

void Room::generateCorridors() {
	if (top == nullptr) {
		for (int i = 13; i <= 16; i++) {
			grid[i][2] = TOP_WALL;
		}
	}
	else {
		for (int i = 0; i < 2; i++) {
			grid[13][i] = LEFT_WALL;
			grid[14][i] = FLOOR;
			grid[15][i] = FLOOR;
			grid[16][i] = RIGHT_WALL;
		}
		grid[14][2] = HORIZONTAL_DOOR;
	}
	if (left == nullptr) {
		// Walls
		for (int i = 13; i <= 16; i++) {
			grid[2][i] = LEFT_WALL;
		}
	}
	else {
		for (int i = 0; i < 2; i++) {
			grid[i][13] = TOP_WALL;
			grid[i][14] = FLOOR;
			grid[i][15] = FLOOR;
			grid[i][16] = BOTTOM_WALL;
		}
		grid[2][13] = TOP_WALL;
		grid[2][14] = VERTICAL_DOOR;
		grid[2][16] = BOTTOM_WALL;
	}
	if (right == nullptr) {
		// Walls
		for (int i = 13; i <= 16; i++) {
			grid[27][i] = RIGHT_WALL;
		}
	}
	else {
		for (int i = 28; i < 30; i++) {
			grid[i][13] = TOP_WALL;
			grid[i][14] = FLOOR;
			grid[i][15] = FLOOR;
			grid[i][16] = BOTTOM_WALL;
		}
		grid[27][13] = TOP_WALL;
		grid[27][14] = VERTICAL_DOOR;
		grid[27][16] = BOTTOM_WALL;
	}
	if (bottom == nullptr) {
		// Walls
		for (int i = 13; i <= 16; i++) {
			grid[i][27] = BOTTOM_WALL;
		}
	}
	else {
		for (int i = 28; i < 30; i++) {
			grid[13][i] = LEFT_WALL;
			grid[14][i] = FLOOR;
			grid[15][i] = FLOOR;
			grid[16][i] = RIGHT_WALL;
		}
		grid[14][27] = HORIZONTAL_DOOR;
	}
}

void Room::generateTiles() {
	for (int i = 0; i < TILES_PER_ROOM; i++) {
		for (int j = 0; j < TILES_PER_ROOM; j++) {
			loadMapObject(grid[j][i], i, j);
		}
	}
	// TODO spawn chest if it is a treasure room
}

void Room::loadMapObject(char character, int i, int j) {
	int x = j * TILE_SIZE + offsetRoomX + HALF_TILE_SIZE;
	int y = i * TILE_SIZE + offsetRoomY + HALF_TILE_SIZE;
	switch (character) {
	case FLOOR: {
		tiles.push_back(new MappedTile("res/tiles/floor.png", x, y, 160, rand() % 10, game));
		break;
	}
	case TOP_LEFT_WALL: {
		Tile* tile = new MappedTile("res/tiles/wall.png", x, y, 160, 0, game);
		tiles.push_back(tile);
		space->addStaticActor(tile);
		break;
	}
	case TOP_RIGHT_WALL: {
		Tile* tile = new MappedTile("res/tiles/wall.png", x, y, 160, 3, game);
		tiles.push_back(tile);
		space->addStaticActor(tile);
		break;
	}
	case BOTTOM_LEFT_WALL: {
		Tile* tile = new MappedTile("res/tiles/wall.png", x, y, 160, 1, game);
		tiles.push_back(tile);
		space->addStaticActor(tile);
		break;
	}
	case BOTTOM_RIGHT_WALL: {
		Tile* tile = new MappedTile("res/tiles/wall.png", x, y, 160, 2, game);
		tiles.push_back(tile);
		space->addStaticActor(tile);
		break;
	}
	case TOP_WALL: {
		Tile* tile = new MappedTile("res/tiles/wall.png", x, y, 160, 4 + rand() % 2, game);
		tiles.push_back(tile);
		space->addStaticActor(tile);
		break;
	}
	case LEFT_WALL: {
		Tile* tile = new MappedTile("res/tiles/wall.png", x, y, 160, 6 + i % 2, game);
		tiles.push_back(tile);
		space->addStaticActor(tile);
		break;
	}
	case RIGHT_WALL: {
		Tile* tile = new MappedTile("res/tiles/wall.png", x, y, 160, 8 + i % 2, game);
		tiles.push_back(tile);
		space->addStaticActor(tile);
		break;
	}
	case BOTTOM_WALL: {
		Tile* tile = new MappedTile("res/tiles/wall.png", x, y, 160, 10 + j % 2, game);
		tiles.push_back(tile);
		space->addStaticActor(tile);
		break;
	}
	case HORIZONTAL_DOOR: {
		tiles.push_back(new MappedTile("res/tiles/floor.png", x, y, 160, rand() % 10, game));
		tiles.push_back(new MappedTile("res/tiles/floor.png", x + TILE_SIZE, y, 160, rand() % 10, game));
		doors.push_back(new Door("res/tiles/horizontal_door.png", x, y, 32, 16, 64, 16, game));
		break;
	}
	case VERTICAL_DOOR: {
		tiles.push_back(new MappedTile("res/tiles/floor.png", x, y, 160, rand() % 10, game));
		tiles.push_back(new MappedTile("res/tiles/floor.png", x, y + TILE_SIZE, 160, rand() % 10, game));
		doors.push_back(new Door("res/tiles/vertical_door.png", x, y, 16, 32, 16, 64, game));
		break;
	}
	case ROCK: {
		Tile* tile = new Rock(x, y, game);
		tiles.push_back(new MappedTile("res/tiles/floor.png", x, y, 160, rand() % 10, game));
		tiles.push_back(tile);
		space->addStaticActor(tile);
		break;
	}
	case POND_TOP: {
		Tile* tile = new MappedTile("res/tiles/water.png", x, y, 64, 0, game);
		tiles.push_back(tile);
		space->addLowStaticActor(tile);
		break;
	}
	case POND_BASE: {
		Tile* tile = new MappedTile("res/tiles/water.png", x, y, 64, 1 + rand() % 3, game);
		tiles.push_back(tile);
		space->addLowStaticActor(tile);
		break;
	}
	case BARREL: {
		DestructibleTile* tile = new DestructibleTile("res/tiles/barrel.png", x, y, 64, 3, game);
		tiles.push_back(new MappedTile("res/tiles/floor.png", x, y, 160, rand() % 10, game));
		destructibles.push_back(tile);
		space->addStaticActor(tile);
		break;
	}
	case SPAWN: {
		enemiesToSpawn.push_back(spawner->generateEnemy(x, y, this, game));
		tiles.push_back(new MappedTile("res/tiles/floor.png", x, y, 160, rand() % 10, game));
	}
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
		return new Room(COMMON_ROOM, newRoomXY.x, newRoomXY.y, childCode, space, player, game);
	}
	return nullptr;
}

void Room::printGrid() {
	cout << "\nRoom grid:" << endl;
	for (int i = 0; i < TILES_PER_ROOM; i++) {
		for (int j = 0; j < TILES_PER_ROOM; j++) {
			cout << grid[j][i];
		}
		cout << endl;
	}
}