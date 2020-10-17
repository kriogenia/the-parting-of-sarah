#pragma once
#include "Actor.h"
#include "Animation.h"

#define STARTING_SPEED 3;

class Player :
    public Actor {

public:
    Player(float x, float y, Game* game);

    void update();
    void draw() override;
    void move(int code);
    void stop(int code);

private:
    Animation* animation;

    int movementX;                  // movement on X axis
    int movementY;                  // movement on Y axis
};

