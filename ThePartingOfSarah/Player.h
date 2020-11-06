#pragma once

#include <map>

#include "Actor.h"
#include "Animation.h"

#define STARTING_SPEED 3;
#define DEBUGGING_SPEED 3;

enum eAction {
    IDLE,
    MOVING,
    SHOOTING,
    DYING
};

enum eOrientation {
    UP,
    UP_LEFT,
    UP_RIGHT,
    LEFT,
    RIGHT,
    DOWN_LEFT,
    DOWN_RIGHT,
    DOWN
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
    void importAnimations();

    void setAction();
    void setOrientation(int mouseX, int mouseY);
    void setAxisOrientation(int orientationX, int orientationY);
    void setDiagonalOrientation(int orientationX, int orientationY);
    void setAnimation();

    Animation* animation;

    eAction action;
    eOrientation orientation;

    map<eOrientation, Animation*> idleAnimations;
    map<eOrientation, Animation*> movingAnimations;

    float speed;
};

