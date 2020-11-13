#pragma once

#include "AudioClip.h"
#include "BackgroundAudio.h"
#include <map>

enum eAudioClips {
	TRACK_PLAYER_HIT
};

/* Singleton */
class AudioPlayer
{
public:
	static AudioPlayer* getInstance();
	~AudioPlayer();

	void start();
	void play(eAudioClips key);

private:
	static AudioPlayer* instance;

	AudioPlayer();

	BackgroundAudio* mainTheme;
	map<eAudioClips, AudioClip*> clips;

};