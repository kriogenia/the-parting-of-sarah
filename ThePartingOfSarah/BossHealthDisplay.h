#pragma once

#include "HealthDisplay.h"

class BossHealthDisplay :
    public HealthDisplay
{
public:
    BossHealthDisplay(Game* game);

    void draw() override;
    void update(int currentHp, int maxHp) override;

    bool show;
};

