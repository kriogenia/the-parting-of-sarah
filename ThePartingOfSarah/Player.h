#pragma once
#include "Actor.h"

#define STARTING_SPEED 3;

class Player :
    public Actor {

public:
    Player(float x, float y, Game* game);

    void update();
    void move(int code);
    void stop(int code);

private:
    int movementX;                  // movement on X axis
    int movementY;                  // movement on Y axis
};

