#pragma once

#include "Item.h"

class HeartItem :
    public Item
{
public:
    HeartItem(float x, float y, Game* game);
    /* Item */
    Item* getCopy(float x, float y) override;
private:
    /* Item */
    void applyEffect(Player* player) override;
};

