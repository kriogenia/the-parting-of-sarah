#include "AudioObserver.h"

AudioObserver::AudioObserver(Player* player, AudioPlayer* audio) :
	Observer()
{
	this->audio = audio;
	this->player = player;
}

void AudioObserver::notify(eObserverMessages message) {
	switch (message) {
	case NOTIFICATION_PLAYER_HIT:
		audio->play(TRACK_PLAYER_HIT);
		break;
	}
}