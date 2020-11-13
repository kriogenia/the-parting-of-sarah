#pragma once

#include "Character.h"
#include "Projectile.h"

constexpr auto STARTING_PLAYER_SPEED = 3;
constexpr auto STARTING_PLAYER_SHOT_CADENCE = 30;
constexpr auto STARTING_PLAYER_HP = 3;
constexpr auto PLAYER_PROJECTILE_FILE = "res/sprites/player/Player_Projectile.png";

constexpr auto PLAYER_VISUAL_SIZE = 32;

class Player :
    public Character {

public:
    Player(float x, float y, int* mouseX, int* mouseY, int* scrollX, int* scrollY, Game* game);
    ~Player();

    void update() override;

    void collisionedWith(Actor* actor) override;
    void damage() override;
    // Attributes
    int maxHp;
    // Controls
    void enterInput(int code);
    void stopInput(int code);
    void move();
    Projectile* shoot(int mouseX, int mouseY);
    
private:
    // Initialization
    void importAnimations() override;
    // Update
    void setAction(bool endedAction) override;
    void setOrientation() override;
    void setAxisOrientation(int orientationX, int orientationY);
    //void setDiagonalOrientation(int orientationX, int orientationY);
    void setAnimation() override;
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
    // Mouse and screen reference
    int* mouseX;
    int* mouseY;
    int* scrollX;
    int* scrollY;
};

