#pragma once

#include "HealthDisplay.h"

class BossHealthDisplay :
    public HealthDisplay
{
public:
    BossHealthDisplay(Game* game);
    /* Game cycle */
    void draw() override;
    void update(int currentHp, int maxHp) override;
    /* State */
    bool show;
};

