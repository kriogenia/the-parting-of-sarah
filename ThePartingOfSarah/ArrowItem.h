#pragma once

#include "Item.h"

class ArrowItem :
    public Item
{
public:
    ArrowItem(float x, float y, Game* game);
    /* Item */
    Item* getCopy(float x, float y) override;

private:
    /* Item */
    void applyEffect(Player* player) override;

};

