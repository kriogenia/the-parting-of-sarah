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
	clips.insert_or_assign(TRACK_PLAYER_HIT, new AudioClip("res/audio/player_hit.wav"));
}

void AudioPlayer::play(eAudioClips key) {
	clips[key]->play();
}