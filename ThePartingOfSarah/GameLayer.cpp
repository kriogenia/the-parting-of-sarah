#include "GameLayer.h"

GameLayer::GameLayer(Game* game) :
	Layer(game) 
{
	/* Initiates global game instances */
	audio = AudioPlayer::getInstance();
	hud = new Hud(game);
	player = new Player(0, 0, &mouseX, &mouseY, &scrollX, &scrollY, game);
	player->observers.push_back(new HudObserver(hud));
	player->observers.push_back(new AudioObserver(audio));
	/* Starts audio and first level */
	audio->start();
	init();
}

GameLayer::~GameLayer() 
{
	delete audio;
	delete hud;
	delete level;
	delete player;
	delete space;

	projectiles.clear();
}

void GameLayer::init() 
{
	// Start space and add player
	delete space;
	space = new Space();
	space->addDynamicActor(player);
	// Start new level floor
	delete level;
	level = new Level(floor, space, player, game);
	player->x = level->currentRoom->x * level->currentRoom->mapWidth + level->currentRoom->mapWidth / 2;
	player->y = level->currentRoom->y * level->currentRoom->mapWidth + level->currentRoom->mapWidth / 2;
	// Create environment observers
	level->observers.push_back(new AudioObserver(audio));
	level->observers.push_back(new HudObserver(hud));
	level->expandObservers();
	// Clean actors list
	projectiles.clear();
	// Notify new floor
	for (auto const& observer : level->observers) {
		observer->notify(NOTIFICATION_ENTER_NEW_FLOOR, &floor);
	}
}

void GameLayer::processControls() 
{
	Layer::processControls();
	player->move();
}

void GameLayer::update() 
{
	// Register player shots
	vector<Projectile*> newProjectiles = player->shoot(mouseX + scrollX, mouseY + scrollY);
	for (auto const& projectile : newProjectiles) {
		projectiles.push_back(projectile);
		space->addFlyingDynamicActor(projectile);
	}
	// Modules updates
	space->update();
	player->update();
	level->update();
	hud->updateCrosshair(mouseX, mouseY);
	space->checkDynamicCollisions();
	// Game Over check
	if (player->destructionFlag) {
		//game->loopActive = false;
	}
	// Climb Up floor check
	if (level->bossRoom->completed) {
		climbUp();
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

void GameLayer::draw() 
{
	// Calculate the scroll
	level->moveScroll(&scrollX, &scrollY);
	// Draw the level
	level->draw(scrollX, scrollY);
	// Draw the actors
	player->draw(scrollX, scrollY);
	for (auto const& projectile : projectiles)
		projectile->draw(scrollX, scrollY);
	// Draw the HUD
	hud->draw();
}

void GameLayer::climbUp()
{
	cout << "Floor " << floor << " completed, going up" << endl;
	floor++;
	init();
}

void GameLayer::keysToControl(SDL_Event event) 
{
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

void GameLayer::mouseToControl(SDL_Event event) 
{
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		player->enterInput(event.type);
	}
	if (event.type == SDL_MOUSEBUTTONUP) {
		player->stopInput(event.type);
	}
}