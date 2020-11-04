#pragma once

#include "MappedTile.h"

enum eDoorState {
    DOOR_CLOSED = 0,
    DOOR_OPEN = 1
};

class Door :
    public MappedTile
{
public:
    Door(string filename, int x, int y, int width, int height, int fileWidth, int fileHeight, Game* game);

    void open();
    void close();

private:
    int type;
};

