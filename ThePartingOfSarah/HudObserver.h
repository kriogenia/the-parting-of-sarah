#pragma once

#include "Hud.h"
#include "Observer.h"
#include "Player.h"
#include "Room.h"

class HudObserver :
    public Observer
{
public:
    HudObserver(Hud* hud);

    void notify(eObserverMessages message, void* publisher = nullptr) override;
private:
    Hud* hud;

    // predeclared pointers
    int* integer;
    Item* item;
    Player* player;
    Room* room;
    Boss* boss;
};