#pragma once

#include "Item.h"

/* Adjustment values */
constexpr auto DEFAULT_SHIELD_CD = 480;
constexpr auto SHIELD_CD_REDUCTION = 30;
constexpr auto SHIELD_CD_CAP = 240;

class ShieldItem :
    public Item
{
public:
    ShieldItem(float x, float y, Game* game);
    /* Item */
    Item* getCopy(float x, float y) override;

private:
    /* Item */
    void applyEffect(Player* player) override;

};

