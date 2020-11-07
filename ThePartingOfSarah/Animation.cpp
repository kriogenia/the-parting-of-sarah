#include "Animation.h"

Animation::Animation(string filename, float actorWidth, float actorHeight, float fileWidth, 
	float fileHeight, int updateFrequence, int totalFrames, bool loop, Game* game) :
	
	actorWidth(actorWidth),
	actorHeight(actorHeight),
	fileWidth(fileWidth),
	fileHeight(fileHeight),
	updateFrequence(updateFrequence),
	totalFrames(totalFrames),
	loop(loop),
	game(game),
	updateTime(0),
	currentFrame(0)
{

	// Load texture
	SDL_Surface* surface = IMG_Load(filename.c_str());
	texture = SDL_CreateTextureFromSurface(game->renderer, surface);

	// Calculate frame dimensiones
	frameWidth = fileWidth / totalFrames;
	frameHeigt = fileHeight;

	// Rectangle to show
	source.x = 0;
	source.y = 0;
	source.w = frameWidth;
	source.h = frameHeigt;
}

bool Animation::update() {
	updateTime++;
	if (updateTime > updateFrequence) {
		updateTime = 0;
		currentFrame++;
		if (currentFrame >= totalFrames) {
			currentFrame = 0;
			if (!loop) {
				return true;
			}
		}
	}
	// Update frame rectangle
	source.x = currentFrame * frameWidth;
	return false;
}


void Animation::draw(float x, float y) {
	// Place to render
	SDL_Rect destination;
	destination.x = x - actorWidth / 2;
	destination.y = y - actorHeight / 2;
	destination.w = actorWidth;
	destination.h = actorHeight;

	SDL_RenderCopyEx(game->renderer,
		texture, &source, &destination, 0, NULL, SDL_FLIP_NONE);
}


