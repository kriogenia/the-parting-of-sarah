#include "HudObserver.h"

HudObserver::HudObserver(Hud* hud) :
	Observer() 
{
	this->hud = hud;
}

void HudObserver::notify(eObserverMessages message, void* publisher) {
	Player* player;
	Room* room;
	switch (message) {
	case NOTIFICATION_PLAYER_HIT:
		player = (Player*) publisher;
		hud->updateHealthDisplay(player->hp, player->maxHp);
		break;
	case NOTIFICATION_ENTER_ROOM:
		room = (Room*) publisher;
		hud->updateMap(room);
		break;
	}
}