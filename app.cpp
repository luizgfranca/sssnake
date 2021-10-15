#include "app.h"
#include "strings.cpp"

void App::init() {
    SDL_Init(SDL_INIT_EVERYTHING);

    createWindow();
    startEventLoop();

    SDL_Quit();
}

void App::startEventLoop() {
    this->shouldClose = false;
    this->eventLoop();
}

void App::eventLoop() {
    while (!this->shouldClose)
    {
        SDL_UpdateWindowSurface(this->window);
    }
}

void App::createWindow() {
    this->window = SDL_CreateWindow(
        APP_TITLE, 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        WINDOW_DETAULT_WITDH, 
        WINDOW_DEFAULT_HEIGHT, 
        SDL_WINDOW_RESIZABLE
    );

    this->surface = SDL_GetWindowSurface(this->window);
    this->renderer = SDL_CreateSoftwareRenderer(this->surface);
}