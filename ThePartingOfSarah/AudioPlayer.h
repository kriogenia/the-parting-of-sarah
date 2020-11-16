#pragma once

#include "AudioClip.h"
#include "BackgroundAudio.h"
#include <map>

enum eAudioClips {
	TRACK_PLAYER_HIT,
	TRACK_PLAYER_HEAL,
	TRACK_PLAYER_SHOT,
	TRACK_POWERUP,
	TRACK_DOOR_OPEN,
	TRACK_DOOR_CLOSE,
	TRACK_COIN
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