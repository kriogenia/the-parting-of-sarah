#include "AudioObserver.h"

AudioObserver::AudioObserver(AudioPlayer* audio) :
	Observer()
{
	this->audio = audio;

	relatedClip.insert_or_assign(NOTIFICATION_PLAYER_HIT, TRACK_PLAYER_HIT);
	relatedClip.insert_or_assign(NOTIFICATION_PLAYER_SHOT, TRACK_PLAYER_SHOT);
	relatedClip.insert_or_assign(NOTIFICATION_CLEAR_ROOM, TRACK_DOOR_OPEN);
	relatedClip.insert_or_assign(NOTIFICATION_ENTER_ROOM, TRACK_DOOR_CLOSE);
}

void AudioObserver::notify(eObserverMessages message, void* publisher) {
	Room* room;
	switch (message) {
	case NOTIFICATION_ENTER_ROOM:
		room = (Room*)publisher;
		if (room->cleared) return;
	default:
		audio->play(relatedClip[message]);
	}
}