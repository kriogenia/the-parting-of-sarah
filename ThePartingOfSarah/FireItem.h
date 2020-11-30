#pragma once

#include "Item.h"

constexpr auto PLAYER_PROJECTILE_FILE_ALT = "res/sprites/player/Player_Projectile_Alt.png";

class FireItem :
    public Item
{
public:
    FireItem(float x, float y, Game* game);
    /* Item */
    Item* getCopy(float x, float y) override;

private:
    /* Item */
    void applyEffect(Player* player) override;

};
