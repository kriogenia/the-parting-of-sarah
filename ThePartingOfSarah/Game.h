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

// Screen size constants
constexpr auto WIDTH = 480;
constexpr auto HEIGHT = 480;

constexpr auto OUTLINE_SIZE = 2;

class Game
{
public:
	Game(int seed = -1);

	void loop();

	SDL_Texture* getTexture(string filename);

	SDL_Window* window;
	SDL_Renderer* renderer;
	bool loopActive; 

	Layer* gameLayer;
	TTF_Font* font;
	TTF_Font* fontOutline;

	int seed;

private:

	map<string, SDL_Texture*> mapTextures;
};
