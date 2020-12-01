#include "Game.h"
#include "GameLayer.h"
#include "MenuLayer.h"

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

	/* Fonts initilization */
	TTF_Init();
	fontTitle = TTF_OpenFont("res/upheavtt.ttf", 36);
	fontOutlineTitle = TTF_OpenFont("res/upheavtt.ttf", 36);
	TTF_SetFontOutline(fontOutlineTitle, TITLE_OUTLINE_SIZE);
	fontSubtitle = TTF_OpenFont("res/upheavtt.ttf", 18);
	fontOutlineSubtitle = TTF_OpenFont("res/upheavtt.ttf", 18);
	TTF_SetFontOutline(fontOutlineSubtitle, SUBTITLE_OUTLINE_SIZE);

	gameLayer = new GameLayer(this);
	startLayer = new MenuLayer(this, true);
	restartLayer = new MenuLayer(this, false);
	layer = startLayer;


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

		layer->processControls();
		layer->update();
		layer->draw();

		SDL_RenderPresent(renderer);

		endTick = SDL_GetTicks();
		differenceTick = endTick - initTick;

		if (differenceTick < (1000 / 30)) {
			SDL_Delay((1000 / 30) - differenceTick);
		}
	}

}

void Game::scale() {
	scaledToMax = !scaledToMax;

	if (scaledToMax) {
		SDL_DisplayMode PCdisplay;
		SDL_GetCurrentDisplayMode(0, &PCdisplay);
		float scaleX = (float)PCdisplay.w / (float)WIDTH;
		float scaleY = (float)PCdisplay.h / (float)HEIGHT;
		scaleLower = scaleX;
		if (scaleY < scaleX) {
			scaleLower = scaleY;
		}
		SDL_SetWindowSize(window, WIDTH * scaleLower, HEIGHT * scaleLower);
		SDL_RenderSetScale(renderer, scaleLower, scaleLower);
	}
	else {
		scaleLower = 1;
		SDL_SetWindowSize(window, WIDTH, HEIGHT);
		SDL_RenderSetScale(renderer, 1, 1);
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

