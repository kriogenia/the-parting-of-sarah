#pragma once

#include "AudioClip.h"
#include "BackgroundAudio.h"
#include <map>

enum eAudioClips {
	TRACK_BLOCKED_SHOT,
	TRACK_BOSS_KILLED,
	TRACK_DOOR_OPEN,
	TRACK_DOOR_CLOSE,
	TRACK_COIN,
	TRACK_PLAYER_HIT,
	TRACK_PLAYER_HEAL,
	TRACK_PLAYER_SHOT,
	TRACK_POWERUP
};

/* Singleton */
class AudioPlayer
{
public:
	static AudioPlayer* getInstance();
	~AudioPlayer();

	void start();
	void swap();
	void play(eAudioClips key);

private:
	static AudioPlayer* instance;

	AudioPlayer();

	BackgroundAudio* currentTheme;
	BackgroundAudio* bossTheme;
	BackgroundAudio* mainTheme;

	map<eAudioClips, AudioClip*> clips;

};