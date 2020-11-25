#pragma once

#include "Coin.h"
#include "ShieldItem.h"

constexpr auto NUMBER_OF_ITEMS = 1;

/* Singleton */
class ItemFactory
{
public:
    static ItemFactory* getInstance(Game* game);
    /* Enemy generator */
    Item* generateItem(float x, float y);
    /* Boss generator */
    Item* generateCoin(float x, float y);

private:
    static ItemFactory* instance;
    ItemFactory(Game* game);

    Game* game;

    map<int, Item*> items;

};