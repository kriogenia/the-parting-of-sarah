#include "Layer.h"

Layer::Layer(Game* game) : 
	game(game) {

}

void Layer::processControls()
{
	SDL_Event event;
	SDL_GetMouseState(&mouseX, &mouseY);
	mouseX = mouseX / game->scaleLower;
	mouseY = mouseY / game->scaleLower;
	// Register input
	while (SDL_PollEvent(&event)) {
		// Close game
		if (event.type == SDL_QUIT) game->loopActive = false;
		// Input
		keysToControl(event);
		mouseToControl(event);
	}
}

