#include "HudObserver.h"

HudObserver::HudObserver(Hud* hud) :
	Observer() 
{
	this->hud = hud;
}

void HudObserver::notify(eObserverMessages message, void* publisher) {
	switch (message) {
	case NOTIFICATION_PLAYER_HIT:
		Player* player = (Player*) publisher;
		hud->updateHealthDisplay(player->hp, player->maxHp);
		break;
	}
}