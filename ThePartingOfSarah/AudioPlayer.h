#pragma once

#include "AudioClip.h"
#include "BackgroundAudio.h"
#include <map>

enum eAudioClips {
	TRACK_PLAYER_HIT,
	TRACK_PLAYER_SHOT,
	TRACK_DOOR_OPEN,
	TRACK_DOOR_CLOSE
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