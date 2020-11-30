#include "HudObserver.h"

HudObserver::HudObserver(Hud* hud) :
	Observer() 
{
	this->hud = hud;
}

void HudObserver::notify(eObserverMessages message, void* publisher) {
	switch (message) {
	case NOTIFICATION_POWER_UP:
		hud->updateText("POWER UP"); 
		player = (Player*)publisher;
		hud->updateStats(player);
	case NOTIFICATION_PLAYER_HIT:
	case NOTIFICATION_PLAYER_HEAL:
		player = (Player*) publisher;
		hud->updateHealthDisplay(player->hp, player->maxHp);
		break;
	case NOTIFICATION_ENTER_NEW_FLOOR:
		integer = (int*)publisher;
		hud->updateText("Floor " + to_string(*integer));
		hud->resetMap();
		break;
	case NOTIFICATION_ENTER_ROOM:
		room = (Room*) publisher;
		hud->updateMap(room);
		break;
	case NOTIFICATION_ENTER_BOSS_ROOM:
		boss = (Boss*)publisher;
		cout << boss->name << endl;
		hud->updateText(boss->name, boss->subtitle);
	case NOTIFICATION_BOSS_KILLED:
	case NOTIFICATION_BOSS_HIT:
		boss = (Boss*)publisher;
		hud->updateBossHealthDisplay(boss->hp, boss->maxHp);
		break;
	case NOTIFICATION_PICK_COIN:
		integer = (int*)publisher;
		hud->updateCoins(*integer);
		break;
	case NOTIFICATION_PICK_ITEM:
		item = (Item*)publisher;
		hud->updateText(item->name, item->subtitle);
		break;
	}

}