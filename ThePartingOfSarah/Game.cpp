#include "Game.h"
#include "GameLayer.h"

Game::Game(int seed) :
	seed(seed) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "Error SDL_Init" << SDL_GetError() << endl;
	}
	cout << "Start" << SDL_GetError() << endl;
	if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) < 0) {
		cout << "Error Window y Renderer" << SDL_GetError() << endl;
	}
	SDL_SetWindowTitle(window, "The Parting of Sarah");
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	SDL_ShowCursor(SDL_DISABLE);

	if (seed < 0 || seed >= 10000) {
		cout << "No valid seed provided. Generating..." << endl;
		seed = (unsigned)time(NULL) % 10000;
	}
	cout << "SEED: " << seed << endl;
	srand(seed);

	gameLayer = new GameLayer(this);

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
		gameLayer->draw();

		SDL_RenderPresent(renderer);

		endTick = SDL_GetTicks();
		differenceTick = endTick - initTick;

		if (differenceTick < (1000 / 30)) {
			SDL_Delay((1000 / 30) - differenceTick);
		}
	}

}

SDL_Texture* Game::getTexture(string filename) {
	if (mapTextures.find(filename) == mapTextures.end()) {
		SDL_Surface* surface = IMG_Load(filename.c_str());
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
		mapTextures[filename] = texture;
	}
	return mapTextures[filename];
}

