#include "PauseDisplay.h"

PauseDisplay::PauseDisplay(Game* game) :
	points(&game->gameLayer->points)
{
	this->bg = new Actor("res/backgrounds/bg_pause.png", WIDTH * 0.5, HEIGHT * 0.5, 480, 480, game);
	this->hp = new Text("Vida", WIDTH / 2, HEIGHT / 2 - 50, true, game);
	this->attack = new Text("Ataque", WIDTH / 2, HEIGHT / 2 - 25, true, game);
	this->speed = new Text("Velocidad", WIDTH / 2, HEIGHT / 2, true, game);
	this->cadence = new Text("Cadencia", WIDTH / 2, HEIGHT / 2 + 25, true, game);
	this->projectile = new Text("Disparo", WIDTH / 2, HEIGHT / 2 + 50, true, game);
	this->score = new Text("Puntuación", WIDTH / 2, 3* HEIGHT / 4, true, game);
}

PauseDisplay::~PauseDisplay()
{
	delete bg;
	delete hp;
	delete attack;
	delete speed;
	delete cadence;
	delete projectile;
	delete score;
}

void PauseDisplay::draw()
{
	bg->draw();
	hp->draw();
	attack->draw();
	speed->draw();
	cadence->draw();
	projectile->draw();

	this->score->content = "Puntuación: " + to_string(*points);
	score->draw();
}

void PauseDisplay::update(Player* player)
{
	this->hp->content = "Vida: " + to_string(player->hp) + "/" + to_string(player->maxHp);
	this->attack->content = "Ataque: " + to_string(player->attack).substr(0, 4);
	this->speed->content = "Velocidad: " + to_string(player->speed).substr(0, 4);
	this->cadence->content = "Cadencia: " + to_string(player->shotCadence);
	this->projectile->content = "Disparo: " + to_string(player->shotSize);
}