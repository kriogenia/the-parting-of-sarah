#pragma once

#include "AudioPlayer.h"
#include "Observer.h"
#include "Player.h"
#include "Room.h"

class AudioObserver :
    public Observer
{
public:
    AudioObserver(AudioPlayer* audio);
    /* Observer */
    void notify(eObserverMessages message, void* publisher = nullptr) override;
private:
    AudioPlayer* audio;
    /* Effect - sound map*/
    map<eObserverMessages, eAudioClips> relatedClip;
};