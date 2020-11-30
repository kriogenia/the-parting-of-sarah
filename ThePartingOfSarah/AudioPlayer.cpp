#include "AudioPlayer.h"

AudioPlayer* AudioPlayer::instance = 0;

AudioPlayer* AudioPlayer::getInstance() 
{
	if (instance == 0)
		instance = new AudioPlayer;
	return instance;
}

AudioPlayer::AudioPlayer() 
{
	bossTheme = new BackgroundAudio("res/audio/boss.wav");
	mainTheme = new BackgroundAudio("res/audio/background.wav");
	currentTheme = mainTheme;

	clips.insert_or_assign(TRACK_BLOCKED_SHOT, new AudioClip("res/audio/blocked_shot.wav"));
	clips.insert_or_assign(TRACK_BOSS_KILLED, new AudioClip("res/audio/boss_killed.wav"));
	clips.insert_or_assign(TRACK_DOOR_OPEN, new AudioClip("res/audio/door_open.wav"));
	clips.insert_or_assign(TRACK_DOOR_CLOSE, new AudioClip("res/audio/door_close.wav"));
	clips.insert_or_assign(TRACK_COIN, new AudioClip("res/audio/coin.wav"));
	clips.insert_or_assign(TRACK_PLAYER_HIT, new AudioClip("res/audio/player_hit.wav"));
	clips.insert_or_assign(TRACK_PLAYER_HEAL, new AudioClip("res/audio/player_heal.wav"));
	clips.insert_or_assign(TRACK_PLAYER_SHOT, new AudioClip("res/audio/player_shot.wav"));
	clips.insert_or_assign(TRACK_POWERUP, new AudioClip("res/audio/powerup.wav"));
}

AudioPlayer::~AudioPlayer() 
{
	delete bossTheme;
	delete mainTheme;
	clips.clear();
}

void AudioPlayer::start() 
{
	currentTheme->play();
}

void AudioPlayer::swap()
{
	currentTheme->stop();
	if (currentTheme == mainTheme) {
		currentTheme = bossTheme;
	}
	else {
		currentTheme = mainTheme;
	}
	start();
}

void AudioPlayer::play(eAudioClips key) 
{
	clips[key]->play();
}