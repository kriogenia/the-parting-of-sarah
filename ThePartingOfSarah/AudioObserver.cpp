#include "AudioObserver.h"

AudioObserver::AudioObserver(AudioPlayer* audio) :
	Observer()
{
	this->audio = audio;

	relatedClip.insert_or_assign(NOTIFICATION_PLAYER_HIT, TRACK_PLAYER_HIT);
	relatedClip.insert_or_assign(NOTIFICATION_PLAYER_HEAL, TRACK_PLAYER_HEAL);
	relatedClip.insert_or_assign(NOTIFICATION_PLAYER_SHOOT, TRACK_PLAYER_SHOT);
	relatedClip.insert_or_assign(NOTIFICATION_POWER_UP, TRACK_POWERUP);
	relatedClip.insert_or_assign(NOTIFICATION_CLEAR_ROOM, TRACK_DOOR_OPEN);
	relatedClip.insert_or_assign(NOTIFICATION_ENTER_ROOM, TRACK_DOOR_CLOSE);
	relatedClip.insert_or_assign(NOTIFICATION_PICK_COIN, TRACK_COIN);
	relatedClip.insert_or_assign(NOTIFICATION_PICK_ITEM, TRACK_POWERUP);
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