#pragma once

#include "AudioPlayer.h"
#include "Observer.h"
#include "Player.h"

class AudioObserver :
    public Observer
{
public:
    AudioObserver(AudioPlayer* audio);

    void notify(eObserverMessages message, void* publisher = nullptr) override;
private:
    AudioPlayer* audio;

    map<eObserverMessages, eAudioClips> relatedClip;
};