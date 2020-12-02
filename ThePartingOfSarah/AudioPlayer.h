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
	/* Actions */
	void start();
	void swap();
	void play(eAudioClips key);

private:
	static AudioPlayer* instance;

	AudioPlayer();
	/* Background tracks */
	BackgroundAudio* currentTheme;
	BackgroundAudio* bossTheme;
	BackgroundAudio* mainTheme;
	/* Sound effects */
	map<eAudioClips, AudioClip*> clips;

};