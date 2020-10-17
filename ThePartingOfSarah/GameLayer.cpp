#include "GameLayer.h"

GameLayer::GameLayer(Game* game) :
	Layer(game) {
	init();
}

GameLayer::~GameLayer() {
	delete player;
}

void GameLayer::init() {
	this->scrollX = 0;
	this->scrollY = 0;

	delete background;
	background = new Background(game);
	delete player;
	player = new Player(WIDTH/2, HEIGHT/2, game);
}

void GameLayer::processControls() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		keysToControl(event);
	}
}

void GameLayer::update() {
	player->update();
}

void GameLayer::draw() {
	calculateScroll();

	background->draw();
	player->draw(scrollX, scrollY);
}


void GameLayer::keysToControl(SDL_Event event) {
	int code = event.key.keysym.sym;
	if (event.type == SDL_KEYDOWN) {
		if (code == SDLK_ESCAPE) {
			game->loopActive = false;
			return;
		}
		player->move(code);
	}
	if (event.type == SDL_KEYUP) {
		player->stop(code);
	}
}

void GameLayer::calculateScroll() {
	scrollX = player->x - 200;
	scrollY = player->y - 200;
}
