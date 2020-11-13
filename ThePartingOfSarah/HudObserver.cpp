#include "HudObserver.h"

HudObserver::HudObserver(Player* player, Hud* hud) :
	Observer() 
{
	this->hud = hud;
	this->player = player;
}

void HudObserver::notify(eObserverMessages message) {
	switch (message) {
	case NOTIFICATION_PLAYER_HIT:
		hud->updateHealthDisplay(player->hp, player->maxHp);
		break;
	}
}