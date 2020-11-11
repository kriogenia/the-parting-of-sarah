#pragma once

#include "Actor.h"

constexpr auto PLAYER_PROJECTILE_SPEED = 10;
constexpr auto ENEMY_PROJECTILE_SPEED = 6;

class Projectile :
    public Actor
{
public:
    Projectile(string filename, int x, int y, int mouseX, int mouseY, int size, bool playerShot, Game* game);

    void draw(int scrollX = 0, int scrollY = 0, float rotation = 0.0) override;

    void collisionedWith(Actor* actor) override;

private:
    /* Attributes */
    float speed;
};

