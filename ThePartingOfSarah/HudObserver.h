#pragma once

#include "Hud.h"
#include "Observer.h"
#include "Player.h"

class HudObserver :
    public Observer
{
public:
    HudObserver(Player* player, Hud* hud);

    void notify(eObserverMessages message) override;
private:
    Hud* hud;
    Player* player;
};