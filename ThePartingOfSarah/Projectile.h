#pragma once

#include "Actor.h"

constexpr auto PROJECTILE_SPEED = 10;

class Projectile :
    public Actor
{
public:
    Projectile(string filename, int x, int y, int mouseX, int mouseY, int size, Game* game);

    void draw(float scrollX = 0, float scrollY = 0) override;
    void update();
};

