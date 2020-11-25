#include "ItemFactory.h"

ItemFactory* ItemFactory::instance = 0;

ItemFactory* ItemFactory::getInstance(Game* game) {
    if (instance == 0)
        instance = new ItemFactory(game);
    return instance;
}

ItemFactory::ItemFactory(Game* game) :
    game(game)
{
    items.insert_or_assign(0, new ShieldItem(0, 0, game));
}

Item* ItemFactory::generateItem(float x, float y) 
{
    int pointer = rand() % items.size();
    return items[pointer]->getCopy(x, y);
}

Item* ItemFactory::generateCoin(float x, float y) 
{
    return new Coin(x, y, game);
}