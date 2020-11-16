#include "AudioPlayer.h"

AudioPlayer* AudioPlayer::instance = 0;

AudioPlayer* AudioPlayer::getInstance() {
	if (instance == 0)
		instance = new AudioPlayer;
	return instance;
}

AudioPlayer::AudioPlayer() {
	mainTheme = new BackgroundAudio("res/audio/background.wav");
	clips.insert_or_assign(TRACK_PLAYER_HIT, new AudioClip("res/audio/player_hit.wav"));
	clips.insert_or_assign(TRACK_PLAYER_HEAL, new AudioClip("res/audio/player_heal.wav"));
	clips.insert_or_assign(TRACK_PLAYER_SHOT, new AudioClip("res/audio/player_shot.wav"));
	clips.insert_or_assign(TRACK_POWERUP, new AudioClip("res/audio/powerup.wav"));
	clips.insert_or_assign(TRACK_DOOR_OPEN, new AudioClip("res/audio/door_open.wav"));
	clips.insert_or_assign(TRACK_DOOR_CLOSE, new AudioClip("res/audio/door_close.wav"));
	clips.insert_or_assign(TRACK_COIN, new AudioClip("res/audio/coin.wav"));
}

AudioPlayer::~AudioPlayer() {
	delete mainTheme;
}

void AudioPlayer::start() {
	mainTheme->play();
}

void AudioPlayer::play(eAudioClips key) {
	clips[key]->play();
}