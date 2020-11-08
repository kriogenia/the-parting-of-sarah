#pragma once

#include "Actor.h"

constexpr auto PROJECTILE_SPEED = 10;

class Projectile :
    public Actor
{
public:
    Projectile(string filename, int x, int y, int mouseX, int mouseY, int size, Game* game);

    void draw(int scrollX = 0, int scrollY = 0) override;

    void collisionedWith(Actor* actor) override;
};

