#pragma once

#include "Room.h"

class BossRoom :
    public Room
{
public:
    BossRoom(int x, int y, int number, Space* space, Actor* player, Game* game);
    ~BossRoom();

    void playerEntered() override;

    Tile* ladder = nullptr;
    Character* boss = nullptr;

    bool completed = false;
};

