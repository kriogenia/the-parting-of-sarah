#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <list>
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

class Game
{
public:
	Game(int seed = -1);

	void loop();

	SDL_Window* window;
	SDL_Renderer* renderer;
	bool loopActive; 

	Layer* gameLayer;

	int seed;
};
