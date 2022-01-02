#include "app.h"
#include "EventResolver.h"
#include "strings.cpp"
#include "displayConfig.cpp"

void App::init() {
    SDL_Init(SDL_INIT_EVERYTHING);

    createWindow();
    setupPlayer();
    setupInitialState();
    setupRenderingEngine();
    startEventLoop();
    SDL_Quit();
}

void App::startEventLoop() {
    this->isRunning = true;
    this->eventQueue = new std::queue<Event>();
    this->startFrameTImer();
    this->eventLoop();
}

void App::eventLoop() {
    auto eventResolver = new EventResolver(this);
    
    while (this->isRunning)
    {
        eventResolver->resolveEvents();
        
        if(!this->frameTimer->isDone())
            continue;
        
        this->frameTimer->start(STEP_DELAY);
        player->step();
        renderEngine->renderPlayer(this->player);
        renderEngine->renderFood(this->food);
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

void App::setupRenderingEngine() {
    this->renderEngine = new Renderer(this->renderer);
    this->updateScaling();
}

void App::setupPlayer() {
    this->player = new Snake(
        INITIAL_SNAKE_SIZE, 
        SCREEN_WIDTH, 
        SCREEN_HEIGHT
    );

    this->food = new Food(
        SCREEN_WIDTH, 
        SCREEN_HEIGHT
    );
}

void App::setIsRunning(bool value) {
    this->isRunning = value;
}

void App::updateScaling() {
    this->renderEngine->setScaling(SCREEN_WIDTH, SCREEN_HEIGHT);
}

void App::setupInitialState() {
    player->setHeadPosition(
        (int) floor(SCREEN_WIDTH / 2), 
        (int) ceil(SCREEN_HEIGHT / 2)
    );

    food->generate(player);
}

void App::startFrameTImer() {
    this->frameTimer = new FrameTimer();
    this->frameTimer->start(STEP_DELAY);
}

void App::throwEvent(Event e) {
    this->eventQueue->push(e);
}