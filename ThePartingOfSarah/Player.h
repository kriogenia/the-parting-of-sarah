#pragma once

#include <map>

#include "Character.h"
#include "Projectile.h"

constexpr auto STARTING_PLAYER_SPEED = 3;
constexpr auto STARTING_PLAYER_CADENCE = 30;
constexpr auto STARTING_PLAYER_HP = 3;

enum ePlayerOrientation {
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
    public Character {

public:
    Player(float x, float y, int* mouseX, int* mouseY, int* scrollX, int* scrollY, Game* game);
    ~Player();

    void update() override;
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
    void setOrientation();
    void setAxisOrientation(int orientationX, int orientationY);
    //void setDiagonalOrientation(int orientationX, int orientationY);
    void setAnimation();
    // Animations
    map<ePlayerOrientation, Animation*> idleAnimations;
    map<ePlayerOrientation, Animation*> movingAnimations;
    map<ePlayerOrientation, Animation*> shootingAnimations;
    // States
    eCharacterAction action;
    ePlayerOrientation orientation;
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
    // Mouse and screen reference
    int* mouseX;
    int* mouseY;
    int* scrollX;
    int* scrollY;
};

