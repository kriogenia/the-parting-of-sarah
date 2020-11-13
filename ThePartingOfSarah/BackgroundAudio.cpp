#include "BackgroundAudio.h"

BackgroundAudio::BackgroundAudio(string filename) {
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096); // 2 channels
	mix = Mix_LoadMUS(filename.c_str());
}

BackgroundAudio::~BackgroundAudio() {
	Mix_FreeMusic(mix);
	Mix_CloseAudio();
}

void BackgroundAudio::play() {
	Mix_PlayMusic(mix, -1);
}