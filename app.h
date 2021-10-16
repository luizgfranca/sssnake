#pragma once

#include <SDL2/SDL.h>
#include "Renderer.h"

class App;

class App 
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;
    SDL_Rect viewPort;

    int horizontalScale;
    int verticalScale;
    Renderer *renderEngine;

    bool isRunning;

    SDL_Rect player;

    void startEventLoop();
    void eventLoop();
    void createWindow();
    void setupRenderingEngine();
    void setupInitialState();
    void updateScaling();

    public: 
        void init();
        void setIsRunning(bool value);

};