#pragma once

#include "Item.h"

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
    /* Copies of items to clone */
    vector<Item*> items;

};