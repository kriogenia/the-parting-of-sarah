#pragma once

#include "Item.h"

class FlagItem :
    public Item
{
public:
    FlagItem(float x, float y, Game* game);
    /* Item */
    Item* getCopy(float x, float y) override;

private:
    /* Item */
    void applyEffect(Player* player) override;

};
