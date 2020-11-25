#pragma once

#include "Item.h"

constexpr auto DEFAULT_SHIELD_CD = 240;
constexpr auto SHIELD_CD_REDUCTION = 30;
constexpr auto SHIELD_CD_CAP = 120;

class ShieldItem :
    public Item
{
public:
    ShieldItem(float x, float y, Game* game);
    /* Item */
    Item* getCopy(float x, float y) override;

private:
    void applyEffect(Player* player) override;

};

