#pragma once

#include <SDL2/SDL.h>
#include <queue>
#include "Renderer.h"
#include "Snake.h"
#include "Food.h"
#include "FrameTimer.h"

class App;

enum class Event {
    DIRECTION_UP,
    DIRECTION_DOWN,
    DIRECTION_LEFT,
    DIRECTION_RIGHT
};

class App 
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;

    Renderer *renderEngine;
    FrameTimer *frameTimer;

    bool isRunning;

    void startEventLoop();
    void eventLoop();
    void createWindow();
    void setupRenderingEngine();
    void setupPlayer();
    void setupInitialState();
    void updateScaling();
    void startFrameTImer();

    public: 
        Snake *player;
        Food *food;
        std::queue<Event> *eventQueue;

        void init();
        void setIsRunning(bool value);
        void throwEvent(Event event);

};