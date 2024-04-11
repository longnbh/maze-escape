#ifndef SOUND_H
#define SOUND_H
#include<iostream>
#include <SDL_mixer.h>

class Sound
{
public:
    Sound();
    ~Sound();

    bool khoiTaoSound();
    bool loadSound(const char* filename); // Tai am thanh tu file
    void playSound(); // Phat am thanh

private:
    Mix_Chunk* sound;
};

#endif