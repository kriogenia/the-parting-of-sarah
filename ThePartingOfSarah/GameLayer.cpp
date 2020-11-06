#include "GameLayer.h"

GameLayer::GameLayer(Game* game) :
	Layer(game) {
	init();
}

GameLayer::~GameLayer() {
	delete crosshair;
	delete level;
	delete player;
}

void GameLayer::init() {
	delete space;
	space = new Space();

	delete level;
	level = new Level(floor, space, game);

	delete player;
	player = new Player(
		level->currentRoom->x * level->currentRoom->mapWidth + level->currentRoom->mapWidth / 2,
		level->currentRoom->y * level->currentRoom->mapWidth + level->currentRoom->mapWidth / 2,
		game);
	space->addDynamicActor(player);

	this->scrollX = 0;
	this->scrollY = 0;

	delete crosshair;
	crosshair = new Crosshair(game);


}

void GameLayer::processControls() {
	SDL_GetMouseState(&mouseX, &mouseY);
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		keysToControl(event);
	}
}

void GameLayer::update() {
	space->update();
	player->update(mouseX + scrollX, mouseY + scrollY);
	level->update(player->x, player->y);
	crosshair->update(mouseX, mouseY);
}

void GameLayer::draw() {
	// Calculates the scroll
	level->calculateScroll(player->x, player->y, &scrollX, &scrollY);
	// Draws the actors
	level->draw(scrollX, scrollY);
	player->draw(scrollX, scrollY);
	crosshair->draw();
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
