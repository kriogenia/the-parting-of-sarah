#include "AudioObserver.h"

AudioObserver::AudioObserver(AudioPlayer* audio) :
	Observer()
{
	this->audio = audio;

	relatedClip.insert_or_assign(NOTIFICATION_PLAYER_HIT, TRACK_PLAYER_HIT);
	relatedClip.insert_or_assign(NOTIFICATION_PLAYER_SHOT, TRACK_PLAYER_SHOT);
	relatedClip.insert_or_assign(NOTIFICATION_DOOR_OPEN, TRACK_DOOR_OPEN);
	relatedClip.insert_or_assign(NOTIFICATION_DOOR_CLOSE, TRACK_DOOR_CLOSE);
}

void AudioObserver::notify(eObserverMessages message, void* publisher) {
	audio->play(relatedClip[message]);
}