#pragma once

#include "Actor.h"

/* Default values */
constexpr auto PLAYER_PROJECTILE_SPEED = 10;
constexpr auto ENEMY_PROJECTILE_SPEED = 6;
constexpr auto ENEMY_DEFAULT_DAMAGE = 1.0;

class Projectile :
    public Actor
{
public:
    Projectile(string filename, int x, int y, int destinyX, int destinyY, int width, int height, Game* game);
    Projectile(string filename, int x, int y, int destinyX, int destinyY, int width, int height, float damage, Game* game);
    /* Game cycle */
    void draw(int scrollX = 0, int scrollY = 0, float rotation = 0.0) override;
    /* Actor */
    void collisionedWith(Actor* actor) override;
    /* Attributes */
    float damage;

protected:
    /* Initialization */
    void setVector(int destinyX, int destinyY);
    /* Attributes */
    float speed;
};

