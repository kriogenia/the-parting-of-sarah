#include "MenuLayer.h"


MenuLayer::MenuLayer(Game* game, bool first)
	: Layer(game) 
{
	this->first = first;
	init();
}

MenuLayer::~MenuLayer()
{
	delete background;
	delete button;
	delete points;
	delete crosshair;
}

void MenuLayer::init() 
{
	if (first) {
		background = new Actor("res/backgrounds/bg_start.png", WIDTH * 0.5, HEIGHT * 0.5, 480, 480, game);
		button = new Actor("res/hud/start_button.png", WIDTH * 0.5, HEIGHT * 0.5, 247, 77, game);
	}
	else {
		background = new Actor("res/backgrounds/bg_defeat.png", WIDTH * 0.5, HEIGHT * 0.5, 480, 480, game);
		button = new Actor("res/hud/restart_button.png", WIDTH * 0.5, HEIGHT * 0.7, 300, 77, game);
		points = new Text("SCORE: " + to_string(game->gameLayer->points), WIDTH / 2, HEIGHT * 0.45, true, game);
	}
	crosshair = new Crosshair(game);
}

void MenuLayer::update()
{
	crosshair->update(mouseX, mouseY);
}

void MenuLayer::draw() 
{
	background->draw();
	button->draw();
	crosshair->draw();
	if (!first) {
		points->draw();
	}
	SDL_RenderPresent(game->renderer);
}

void MenuLayer::keysToControl(SDL_Event event) {
	if (event.type == SDL_KEYDOWN) {
		int code = event.key.keysym.sym;
		// Pulsada
		switch (code) {
		case SDLK_ESCAPE: 
			game->loopActive = false;
			break;
		case SDLK_1:
			game->scale();
			break;
		case SDLK_SPACE: 
			game->layer = game->gameLayer;
			break;
		}
	}
}

void MenuLayer::mouseToControl(SDL_Event event) {
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		if (button->containsPoint(mouseX, mouseY)) {
			game->gameLayer->init();
			game->layer = game->gameLayer;
		}
	}
}

