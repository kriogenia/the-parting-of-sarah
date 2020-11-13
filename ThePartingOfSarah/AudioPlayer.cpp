#include "AudioPlayer.h"

AudioPlayer* AudioPlayer::instance = 0;

AudioPlayer* AudioPlayer::getInstance() {
	if (instance == 0)
		instance = new AudioPlayer;
	return instance;
}

AudioPlayer::AudioPlayer() {
	mainTheme = new BackgroundAudio("res/audio/background.wav");
}

AudioPlayer::~AudioPlayer() {
	delete mainTheme;
}

void AudioPlayer::start() {
	mainTheme->play();
}