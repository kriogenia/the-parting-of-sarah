#pragma once

#include "Hud.h"
#include "Observer.h"
#include "Player.h"

class HudObserver :
    public Observer
{
public:
    HudObserver(Hud* hud);

    void notify(eObserverMessages message, void* publisher = nullptr) override;
private:
    Hud* hud;
};