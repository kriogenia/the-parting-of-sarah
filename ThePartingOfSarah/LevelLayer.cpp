#include "LevelLayer.h"

LevelLayer::LevelLayer(Game* game) :
	Layer(game) {
	init();
}

LevelLayer::~LevelLayer() {
	delete background;
}

void LevelLayer::init() {
	delete background;
	background = new Background(game);
}

void LevelLayer::update() {
	cout << "Update LevelLayer" << endl;
}

void LevelLayer::draw() {
	background->draw();
}
