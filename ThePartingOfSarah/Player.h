#pragma once

#include "Character.h"

/* Starting values */
constexpr auto STARTING_PLAYER_ATTACK = 3.0;
constexpr auto STARTING_PLAYER_HP = 3;
constexpr auto STARTING_PLAYER_SHOT_CADENCE = 30;
constexpr auto STARTING_PLAYER_SPEED = 3;
/* Max values*/
constexpr auto CAP_PLAYER_SHOT_CADENCE = 30;
/* Fixed values */
constexpr auto PLAYER_INVULNERABILITY_TIME = 30;
constexpr auto PLAYER_VISUAL_SIZE = 32;
constexpr auto PLAYER_PROJECTILE_FILE = "res/sprites/player/Player_Projectile.png";


class Player :
    public Character {

public:
    Player(float x, float y, int* mouseX, int* mouseY, int* scrollX, int* scrollY, Game* game);
    ~Player();

    void update() override;
    void draw(int scrollX = 0, int scrollY = 0, float rotation = 0.0) override;

    void collisionedWith(Actor* actor) override;
    void damage(float damage = 1.0) override;
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
    float attack;
    int shotCadence;
    // States
    int shotTime;
    int invulnerabilityTime;
    // Mouse and screen reference
    int* mouseX;
    int* mouseY;
    int* scrollX;
    int* scrollY;
};

