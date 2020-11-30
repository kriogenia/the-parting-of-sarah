#include "ItemFactory.h"

#include "ArrowItem.h"
#include "Coin.h"
#include "FireItem.h"
#include "FlagItem.h"
#include "HeartItem.h"
#include "ShieldItem.h"

ItemFactory* ItemFactory::instance = 0;

ItemFactory* ItemFactory::getInstance(Game* game) {
    if (instance == 0)
        instance = new ItemFactory(game);
    return instance;
}

ItemFactory::ItemFactory(Game* game) :
    game(game)
{
    items.push_back(new ShieldItem(0, 0, game));
    items.push_back(new ArrowItem(0, 0, game));
    items.push_back(new FlagItem(0, 0, game));
    items.push_back(new HeartItem(0, 0, game));
    items.push_back(new FireItem(0, 0, game));
}

Item* ItemFactory::generateItem(float x, float y) 
{
    int pointer = rand() % items.size();
    pointer = 4;                                        // Debug
    return items[pointer]->getCopy(x, y);
}

Item* ItemFactory::generateCoin(float x, float y) 
{
    return new Coin(x, y, game);
}