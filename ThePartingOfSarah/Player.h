#pragma once

#include <map>

#include "Character.h"
#include "Projectile.h"

constexpr auto STARTING_PLAYER_SPEED = 3;
constexpr auto STARTING_PLAYER_CADENCE = 30;
constexpr auto STARTING_PLAYER_HP = 3;

class Player :
    public Character {

public:
    Player(float x, float y, int* mouseX, int* mouseY, int* scrollX, int* scrollY, Game* game);
    ~Player();

    void update() override;

    void collisionedWith(Actor* actor) override;

    // Controls
    void enterInput(int code);
    void stopInput(int code);
    void move();
    Projectile* shoot(int mouseX, int mouseY);
    
private:
    // Initialization
    void importAnimations() override;
    // Update
    void setAction(bool endedAction);
    void setOrientation();
    void setAxisOrientation(int orientationX, int orientationY);
    //void setDiagonalOrientation(int orientationX, int orientationY);
    void setAnimation();
    // Animations
    map<eCharacterOrientation, Animation*> idleAnimations;
    map<eCharacterOrientation, Animation*> shootingAnimations;
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

