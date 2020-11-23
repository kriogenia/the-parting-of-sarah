#pragma once

#include "Room.h"

class BossRoom :
    public Room
{
public:
    BossRoom(int x, int y, int number, Space* space, Actor* player, Game* game);
    ~BossRoom();
    /* Environment */
    void spawnStair() override;
    /* Room */
    void update() override;
    void playerEntered() override;

    Tile* stair = nullptr;
    Character* boss = nullptr;

    bool completed = false;
};

