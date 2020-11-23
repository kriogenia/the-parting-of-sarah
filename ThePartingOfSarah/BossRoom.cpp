#include "BossRoom.h"

BossRoom::BossRoom(int x, int y, int number, Space* space, Actor* player, Game* game) :
	Room(BOSS_ROOM, x, y, number, space, player, game)
{
	boss = spawner->generateBoss(
		offsetRoomX + TILES_PER_ROOM * TILE_SIZE / 2, offsetRoomY + TILES_PER_ROOM * TILE_SIZE / 2, this, game);
	enemiesToSpawn.push_back(boss);
}

BossRoom::~BossRoom()
{
	delete boss;
}

void BossRoom::playerEntered() {
	Room::playerEntered();
	for (auto const& observer : observers) {
		cout << "Entered the Boss Room - ";
		observer->notify(NOTIFICATION_ENTER_BOSS_ROOM, boss);
	}
}

