#pragma once

#include <iostream>
#include <string>
#include <list>
#include <time.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Layer.h"
class Layer;

using namespace std;

// Screen size constants
#define WIDTH 960
#define HEIGHT 960

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
