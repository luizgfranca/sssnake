#pragma once

#include <SDL2/SDL.h>
#include "Renderer.h"
#include "Snake.h"
#include "FrameTimer.h"

class App;

class App 
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;

    Renderer *renderEngine;
    FrameTimer *frameTimer;

    bool isRunning;

    Snake *player;

    void startEventLoop();
    void eventLoop();
    void createWindow();
    void setupRenderingEngine();
    void setupPlayer();
    void setupInitialState();
    void updateScaling();
    void startFrameTImer();

    public: 
        void init();
        void setIsRunning(bool value);

};