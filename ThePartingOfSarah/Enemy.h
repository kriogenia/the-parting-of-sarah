#pragma once

#include "Character.h"
#include "Environment.h"

constexpr auto COIN_RARITY = 1;             // Chances of enemy to drop a coin = 1/COIN_RARITY

enum eBasicEnemyClass {
    BEE,
    BIRD,
    GHOST,
    PIG,
    PLANT,
    RADISH,
    SNAIL,
    STONE
};

/* interface */
class Enemy :
    public Character
{
public:
    Enemy(string filename, float x, float y, int width, int height, Environment* room, Game* game);
    ~Enemy();
    /* Actor */
    void collisionedWith(Actor* actor) override;
    /* Character */
    void damage(float damage = 1.0) override;
    /* Attributes */
    unsigned int points = 0;

protected:
    /* Character */
    void setMovement() override;
    void setAction(bool endAction) override;
    void setOrientation() override;
    /* Enemy interface */
    virtual void death();
    virtual void hit();
    /* Room pointer */
    Environment* room;
    /* Basic animations */
    Animation* dyingAnimation;
    map<eCharacterOrientation, Animation*> hitAnimations;
};

