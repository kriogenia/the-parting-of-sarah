#pragma once

#include "BackgroundAudio.h"

/* Singleton */
class AudioPlayer
{
public:
	static AudioPlayer* getInstance();
	~AudioPlayer();

	void start();

private:
	static AudioPlayer* instance;

	AudioPlayer();

	BackgroundAudio* mainTheme;
};