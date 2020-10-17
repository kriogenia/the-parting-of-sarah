#include "GameLayer.h"

GameLayer::GameLayer(Game* game) :
	Layer(game) {
	init();
}

GameLayer::~GameLayer() {
	delete player;
}

void GameLayer::init() {
	delete player;
	player = new Player(WIDTH/2, HEIGHT/2, game);
}

void GameLayer::processControls() {
	cout << "Process Controls GameLayer" << endl;
}

void GameLayer::update() {
	cout << "Update GameLayer" << endl;
}

void GameLayer::draw() {
	player->draw();
}
