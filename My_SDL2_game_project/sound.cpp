#include "sound.h"
#include <iostream>

Sound::Sound() {
    sound = nullptr;
}

Sound::~Sound() {
    if (sound != nullptr) {
        Mix_FreeChunk(sound);
        sound = nullptr;
    }
}

bool Sound::khoiTaoSound()
{
    bool res = true;
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "Mix_OpenAudio failed: " << Mix_GetError() << std::endl;
        res = false;
    }
    return res;
}

bool Sound::loadSound(const char* filename) {
    sound = Mix_LoadWAV(filename);
    if (sound == nullptr) {
        std::cerr << "Failed to load sound: " << Mix_GetError() << std::endl;
        return false;
    }
    return true;
}

void Sound::playSound() {
    Mix_PlayChannel(-1, sound, 0);
}
