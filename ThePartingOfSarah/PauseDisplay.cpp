#include "PauseDisplay.h"

PauseDisplay::PauseDisplay(Game* game)
{
	this->bg = new Actor("res/backgrounds/bg_pause.png", WIDTH * 0.5, HEIGHT * 0.5, 480, 480, game);
	this->hp = new Text("HP", WIDTH / 2, HEIGHT / 2 - 50, true, game);
	this->attack = new Text("ATTACK", WIDTH / 2, HEIGHT / 2 - 25, true, game);
	this->speed = new Text("SPEED", WIDTH / 2, HEIGHT / 2, true, game);
	this->cadence = new Text("SHOT CADENCE", WIDTH / 2, HEIGHT / 2 + 25, true, game);
	this->projectile = new Text("PROJECTILE", WIDTH / 2, HEIGHT / 2 + 50, true, game);
}

PauseDisplay::~PauseDisplay()
{
	delete bg;
	delete hp;
	delete attack;
	delete speed;
	delete cadence;
	delete projectile;
}

void PauseDisplay::draw()
{
	bg->draw();
	hp->draw();
	attack->draw();
	speed->draw();
	cadence->draw();
	projectile->draw();
}

void PauseDisplay::update(Player* player)
{
	this->hp->content = "HP: " + to_string(player->hp) + "/" + to_string(player->maxHp);
	this->attack->content = "Attack: " + to_string(player->attack).substr(0, 4);
	this->speed->content = "Speed: " + to_string(player->speed).substr(0, 4);
	this->cadence->content = "Shot cadence: " + to_string(player->shotCadence);
	this->projectile->content = "Projectile: " + to_string(player->shotSize);
}