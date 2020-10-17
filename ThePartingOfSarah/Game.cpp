#include "Game.h"
#include "GameLayer.h"
#include "LevelLayer.h"

Game::Game() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "Error SDL_Init" << SDL_GetError() << endl;
	}
	cout << "Start" << SDL_GetError() << endl;
	if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) < 0) {
		cout << "Error Window y Renderer" << SDL_GetError() << endl;
	}
	SDL_SetWindowTitle(window, "The Parting of Sarah");
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	layers.clear();
	levelLayer = new LevelLayer(this);
	gameLayer = new GameLayer(this);
	layers.push_back(levelLayer);
	layers.push_back(gameLayer);

	loopActive = true;
	loop();

	SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
	SDL_Quit();
}

void Game::loop() {
	int initTick;
	int endTick;
	int differenceTick;

	while (loopActive) {
		initTick = SDL_GetTicks();

		gameLayer->processControls();
		gameLayer->update();

		for (auto const& layer : layers) {
			layer->draw();
		}

		SDL_RenderPresent(renderer);

		endTick = SDL_GetTicks();
		differenceTick = endTick - initTick;

		if (differenceTick < (1000 / 30)) {
			SDL_Delay((1000 / 30) - differenceTick);
		}
	}

}
