#include "GameLayer.h"

GameLayer::GameLayer(Game* game) :
	Layer(game) {
	init();
}

GameLayer::~GameLayer() {
	delete crosshair;
	delete level;
	delete player;
	delete space;

	projectiles.clear();
}

void GameLayer::init() {

	this->scrollX = 0;
	this->scrollY = 0;

	delete space;
	space = new Space();

	delete level;
	level = new Level(floor, space, game);

	delete player;
	player = new Player(
		level->currentRoom->x * level->currentRoom->mapWidth + level->currentRoom->mapWidth / 2,
		level->currentRoom->y * level->currentRoom->mapWidth + level->currentRoom->mapWidth / 2,
		&mouseX, &mouseY, &scrollX, &scrollY, game);
	space->addDynamicActor(player);

	delete crosshair;
	crosshair = new Crosshair(game);

	projectiles.clear();

}

void GameLayer::processControls() {
	SDL_GetMouseState(&mouseX, &mouseY);
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		keysToControl(event);
		mouseToControl(event);
	}
	player->move();
	// Register player shot
	Projectile* projectile = player->shoot(mouseX + scrollX, mouseY + scrollY);
	if (projectile != nullptr) {
		projectiles.push_back(projectile);
		space->addFlyingDynamicActor(projectile);
	}
}

void GameLayer::update() {
	space->update();
	player->update();
	level->update(player);
	crosshair->update(mouseX, mouseY);
	space->checkDynamicCollisions();
	// Game Over check
	if (player->destructionFlag) {
		game->loopActive = false;
	}
	// Projectiles deletion
	list<Projectile*> projectilesToDelete;
	for (auto const& projectile : projectiles) {
		if (projectile->destructionFlag) {
			projectilesToDelete.push_back(projectile);
		}
	}
	for (auto const& projectile : projectilesToDelete) {
		space->removeFlyingDynamicActor(projectile);
		projectiles.remove(projectile);
	}

}

void GameLayer::draw() {
	// Calculate the scroll
	level->calculateScroll(player->x, player->y, &scrollX, &scrollY);
	// Draw the actors
	level->draw(scrollX, scrollY);
	player->draw(scrollX, scrollY);
	for (auto const& projectile : projectiles)
		projectile->draw(scrollX, scrollY);
	crosshair->draw();
}

void GameLayer::keysToControl(SDL_Event event) {
	int code = event.key.keysym.sym;
	if (event.type == SDL_KEYDOWN) {
		if (code == SDLK_ESCAPE) {
			game->loopActive = false;
			return;
		}
		player->enterInput(code);
	}
	if (event.type == SDL_KEYUP) {
		player->stopInput(code);
	}
}

void GameLayer::mouseToControl(SDL_Event event) {
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		player->enterInput(event.type);
	}
	if (event.type == SDL_MOUSEBUTTONUP) {
		player->stopInput(event.type);
	}
}