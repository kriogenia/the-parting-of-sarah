#pragma once

#include "Character.h"

/* Starting values */
constexpr auto STARTING_PLAYER_ATTACK = 1.5;
constexpr auto STARTING_PLAYER_HP = 3;
constexpr auto STARTING_PLAYER_SHOT_CADENCE = 30;
constexpr auto STARTING_PLAYER_SPEED = 3;
constexpr auto STARTING_PLAYER_PROJECTILE_SIZE = 7;
/* Max values*/
constexpr auto CAP_PLAYER_ATTACK = 5.0;
constexpr auto CAP_PLAYER_HP = 10;
constexpr auto CAP_PLAYER_SHOT_CADENCE = 16;
constexpr auto CAP_PLAYER_SPEED = 6.5;
constexpr auto CAP_PLAYER_PROJECTILE_SIZE = 14;
/* Fixed values */
constexpr auto POWER_UP_COIN_COST = 10;
constexpr auto HEAL_COIN_COST = 5;
constexpr auto PLAYER_INVULNERABILITY_TIME = 30;
constexpr auto PLAYER_VISUAL_SIZE = 32;
constexpr auto PLAYER_PROJECTILE_FILE = "res/sprites/player/Player_Projectile.png";

enum ePlayerStats {
    ATTACK_DAMAGE,
    HEALTH_POINTS,
    SHOT_CADENCE,
    MOVEMENT_SPEED,
    PROJECTILE_SIZE
};

class Player :
    public Character {

public:
    Player(float x, float y, int* mouseX, int* mouseY, int* scrollX, int* scrollY, Game* game);
    ~Player();
    /* Game cycle */
    void update() override;
    void draw(int scrollX = 0, int scrollY = 0, float rotation = 0.0) override;
    /* Character */
    void collisionedWith(Actor* actor) override;
    void damage(float damage = 1.0) override;
    /* Player */
    void coinUp();
    void powerUp();
    /* Base attributes */
    int maxHp;
    float attack;
    int shotCadence;
    int shotSize;
    /* Items related atts */
    int coins;
    int shieldCd;
    string projectileFile;
    // Controls
    void enterInput(int code);
    void stopInput(int code);
    void move();
    Projectile* shoot(int mouseX, int mouseY);
    // Debug
    void print();
    
private:
    // Initialization
    void importAnimations() override;
    /* Character update */
    void setAction(bool endedAction) override;
    void setOrientation() override;
    void setAxisOrientation(int orientationX, int orientationY);
    //void setDiagonalOrientation(int orientationX, int orientationY);
    void setAnimation() override;
    /* Player update */
    void updateShield();
    // Animations
    map<eCharacterOrientation, Animation*> idleAnimations;
    map<eCharacterOrientation, Animation*> shootingAnimations;
    // Movement and controls
    int moveUp = 0;
    int moveLeft = 0;
    int moveRight = 0;
    int moveDown = 0;
    bool shooting = false;
    // Cooldowns
    int invulnerabilityTime;
    bool shieldUp;
    int shieldTime;
    int shotTime;
    // Mouse and screen reference
    int* mouseX;
    int* mouseY;
    int* scrollX;
    int* scrollY;
};

