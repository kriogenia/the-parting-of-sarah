#pragma once

#include "Actor.h"
#include "Animation.h"
#include "Observer.h"
#include "Projectile.h"

/* Common character actions */
enum eCharacterAction {
    IDLE,
    MOVING,
    SHOOTING,
    HIDING,
    HIT,
    RUNNING,
    DYING
};

enum eCharacterOrientation {
    UP,
    LEFT,
    RIGHT,
    DOWN
};

/* interface */
class Character :
    public Actor
{
public:
    Character(string filename, float x, float y, int width, int height, Game* game);
    ~Character();
    /* Game cycle */
    virtual void update();
    void draw(int scrollX = 0, int scrollY = 0, float rotation = 0.0) override;
    /* Character interface */
    virtual void damage(float damage = 1.0);
    /* Attributes */
    int hp;
    bool flying;
    float speed;
    /* Observers */
    list<Observer*> observers;

protected:
    /* Character interface */
    // Initialization
    virtual void importAnimations() = 0;
    // Character template
    virtual void setMovement();
    virtual void setAction(bool endedAction);
    virtual void setOrientation();
    virtual void setAnimation();
    /* States */
    eCharacterAction action;
    eCharacterOrientation orientation;
    /* Animations */
    Animation* animation;
    map<eCharacterOrientation, Animation*> movingAnimations;
};

