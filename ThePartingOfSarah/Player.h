#pragma once

#include <map>

#include "Actor.h"
#include "Animation.h"

#define STARTING_SPEED 3;
#define DEBUGGING_SPEED 15;

enum eAction {
    IDLE,
    MOVING,
    SHOOTING
};

enum eOrientation {
    UP_LEFT,
    UP_RIGHT,
    DOWN_LEFT,
    DOWN_RIGHT
};

class Player :
    public Actor {

public:
    Player(float x, float y, Game* game);
    ~Player();

    void update(int mouseX, int mouseY);
    void draw(float scrollX = 0, float scrollY = 0) override;
    void move(int code);
    void stop(int code);
    
private:
    eOrientation getOrientation(int mouseX, int mouseY);
    Animation* getAnimation();

    Animation* animation;

    int movementX;                  // movement on X axis
    int movementY;                  // movement on Y axis

    eAction action;
    eOrientation orientation;

    map<eOrientation, Animation*> movingAnimations;
};

