#include "audio.h"
#include<SDL2/SDL.h>
#include "Define.h"
#include<SDL2/SDL_audio.h>
Audio::~Audio() {
    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wavBuffer);
}

void Audio::load(const char* filename) {
    SDL_LoadWAV(filename, &wavSpec, &wavBuffer, &wavLength);
    deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
}

void Audio::play() {
    SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceId, 0);
}

void Audio::stop() {
    SDL_PauseAudioDevice(deviceId, 1);
}
