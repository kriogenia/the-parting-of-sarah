#pragma once

#include <map>

#include "Actor.h"
#include "Animation.h"
#include "Projectile.h"

constexpr auto STARTING_SPEED = 3;
constexpr auto STARTING_CADENCE = 30;

constexpr auto DEBUGGING_SPEED  = 3;

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
    // Controls
    void enterInput(int code);
    void stopInput(int code);
    void move();
    Projectile* shoot(int mouseX, int mouseY);
    
private:
    // Initialization
    void importAnimations();
    // Update
    void setAction(bool endedAction);
    void setOrientation(int mouseX, int mouseY);
    void setAxisOrientation(int orientationX, int orientationY);
    //void setDiagonalOrientation(int orientationX, int orientationY);
    void setAnimation();
    // Animations
    Animation* animation;
    map<eOrientation, Animation*> idleAnimations;
    map<eOrientation, Animation*> movingAnimations;
    map<eOrientation, Animation*> shootingAnimations;
    // States
    eAction action;
    eOrientation orientation;
    // Movement and controls
    int moveUp = 0;
    int moveLeft = 0;
    int moveRight = 0;
    int moveDown = 0;
    bool shooting = false;
    // Attributes
    int shotTime;
    int shotCadence;
    float speed;
};

