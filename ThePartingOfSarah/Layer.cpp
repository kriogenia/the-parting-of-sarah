#include "Layer.h"

Layer::Layer(Game* game) : 
	game(game) {

}

void Layer::processControls()
{
	SDL_Event event;
	SDL_GetMouseState(&mouseX, &mouseY);
	// Register input
	while (SDL_PollEvent(&event)) {
		keysToControl(event);
		mouseToControl(event);
	}
}

