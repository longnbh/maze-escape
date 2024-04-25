#ifndef SOUND_H
#define SOUND_H
#include<iostream>
#include <string>
#include <SDL_mixer.h>
const int numSound = 9;

class Sound
{
public:
    Sound();
    ~Sound();

    bool khoiTaoSound();
    bool loadSound(const char* filename); // Tai am thanh tu file
    void playSound(); // Phat am thanh
    void stopSound();
    void playRandom();
private:
    Mix_Chunk* sound;
};

#endif