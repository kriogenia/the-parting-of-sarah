#pragma once

#include <iostream>
#include <string>
#include <list>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Layer.h"
class Layer;

using namespace std;

// Screen size constants
#define WIDTH 960
#define HEIGHT 480

class Game
{
public:
	Game();

	void loop();

	SDL_Window* window;
	SDL_Renderer* renderer;
	bool loopActive; 

	Layer* gameLayer;
};
