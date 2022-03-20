#pragma once

#include <SDL2/SDL.h>
#include <queue>
#include "Renderer.h"
#include "Snake.h"
#include "Food.h"
#include "FrameTimer.h"
#include "GameLogicProcessor.h"
#include "event.h"

class GameLogicProcessor;

class App 
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;

    GameLogicProcessor *gameLogicProcessor;
    Renderer *renderEngine;
    FrameTimer *frameTimer;

    bool isRunning;
    bool isGameOver;

    void startEventLoop();
    void eventLoop();
    void createWindow();
    void setupRenderingEngine();
    void setupApplication();
    void setupEnvironment();
    void setupInitialState();
    void updateScaling();
    void startFrameTImer();
    void evaluateCapture();
    
    public: 
        Snake *player;
        Food *food;
        std::queue<Event> *eventQueue;

        void init();
        void setIsRunning(bool value);
        void throwEvent(Event event);
        void generateNewFood();
        void growSnake();
        void doNotGrowSnake();
        void shouldGrowSnake();
        void gameOver();
};