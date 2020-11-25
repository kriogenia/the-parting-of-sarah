#pragma once

#include "ArrowItem.h"
#include "Coin.h"
#include "FlagItem.h"
#include "ShieldItem.h"

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

    vector<Item*> items;

};