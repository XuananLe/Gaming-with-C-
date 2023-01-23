#ifndef DEFINE_H
#define DEFINE_H
#include<SDL2/SDL.h>
#include<iostream>
#include<map>
#include<SDL2/SDL_mixer.h>
#include<SDL2/SDL_ttf.h>
#include<vector>
#include<SDL2/SDL_image.h>
#include<random>
#include<ctime>

const int HEALTH = 3;
const int SCREEN_WIDTH = 1500;
const int SCREEN_HEIGHT = 1000;
const int SPACESHIP_WIDTH = 90;
const int SPACESHIP_HEIGHT = 90;
const int MAX_BULLET_AT_A_TIME = 3;
const char title[1000] = "My first game ever";
const int SCREEN_BPP = 32;
const int SHIP_VEL = 12;
const int BULLET_VEL = 7;
const int FPS = 60;
const int frameDelay = 1000 / FPS;
const Uint64 FrameStart = SDL_GetTicks64();
const int frameTime = SDL_GetTicks64() - FrameStart;
const void FramePerSecond(){if (frameDelay > FrameStart){SDL_Delay(frameDelay - FrameStart);}}
// bien static de hoat dong trong TOAN BO CHUONG TRINH
static SDL_Window *window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
static SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
static SDL_Event event;
#endif