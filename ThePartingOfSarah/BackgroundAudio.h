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
    void stop();

private:
    Mix_Music* mix;

    string filename;
};

