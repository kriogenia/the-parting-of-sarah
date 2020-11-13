#pragma once

#include "AudioPlayer.h"
#include "Observer.h"
#include "Player.h"

class AudioObserver :
    public Observer
{
public:
    AudioObserver(Player* player, AudioPlayer* audio);

    void notify(eObserverMessages message) override;
private:
    AudioPlayer* audio;
    Player* player;
};