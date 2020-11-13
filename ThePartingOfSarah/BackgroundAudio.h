#pragma once

#include <SDL_mixer.h> 
#include <iostream>
#include <string> 
using namespace std;


class BackgroundAudio
{
public:
    BackgroundAudio(string filename);
    ~BackgroundAudio();

    void play();

private:
    Mix_Music* mix;
};

