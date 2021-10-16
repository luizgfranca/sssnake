#pragma once

#include <SDL2/SDL.h>

class App;

class App 
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;

    bool isRunning;

    void startEventLoop();
    void eventLoop();
    void createWindow();

    public: 
        void init();
        void setIsRunning(bool value);

};