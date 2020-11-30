#pragma once

#include "Item.h"

constexpr auto KNIFE_ATTACK_MULTIPLIER = 1.25;

class KnifeItem :
    public Item
{
public:
    KnifeItem(float x, float y, Game* game);
    /* Item */
    Item* getCopy(float x, float y) override;

private:
    /* Item */
    void applyEffect(Player* player) override;

};

