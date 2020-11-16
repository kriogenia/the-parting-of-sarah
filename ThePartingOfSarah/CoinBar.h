#pragma once

#include "Actor.h"

constexpr auto COIN_HEIGHT = 9;
constexpr auto COIN_WIDTH = 16;

class CoinBar :
    public Actor
{
public:
    CoinBar(float x, float y, int startingHeight, Game* game);

    void draw(int scrollX = 0, int scrollY = 0, float rotation = 0.0) override;
    void update(int currentCoins);

    int currentHeight;
};

