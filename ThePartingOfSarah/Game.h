#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Layer.h"
class Layer;

using namespace std;

/* Screen size */
constexpr auto WIDTH = 480;
constexpr auto HEIGHT = 480;
/* Text */
constexpr auto TITLE_OUTLINE_SIZE = 2;
constexpr auto SUBTITLE_OUTLINE_SIZE = 1;

class Game
{
public:
	Game(int seed = -1);

	void loop();
	void scale();
	/* Texture map */
	SDL_Texture* getTexture(string filename);
	/* Window and render */
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool loopActive; 
	/* Layers */
	Layer* layer;
	Layer* gameLayer;
	Layer* startLayer;
	Layer* restartLayer;
	/* Fonts */
	TTF_Font* fontTitle;
	TTF_Font* fontOutlineTitle;
	TTF_Font* fontSubtitle;
	TTF_Font* fontOutlineSubtitle;
	
	int seed;
	float scaleLower = 1;

private:

	map<string, SDL_Texture*> mapTextures;

	bool scaledToMax;

};
