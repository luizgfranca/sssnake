#include "app.h"
#include "EventResolver.h"
#include "strings.cpp"
#include "displayConfig.cpp"

void App::init() {
    SDL_Init(SDL_INIT_EVERYTHING);

    createWindow();
    setupRenderingEngine();
    startEventLoop();

    SDL_Quit();
}

void App::startEventLoop() {
    this->isRunning = true;
    this->setupInitialState();
    this->eventLoop();
}

void App::eventLoop() {
    auto eventResolver = new EventResolver(this);
    
    while (this->isRunning)
    {
        eventResolver->resolveEvents();
        renderEngine->renderPlayer(this->player);
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
    SDL_RenderGetViewport(this->renderer, &this->viewPort);
    
    this->updateScaling();    
}

void App::setupRenderingEngine() {
    this->renderEngine = new Renderer(this->renderer);
}

void App::setIsRunning(bool value) {
    this->isRunning = value;
}

void App::updateScaling() {
    this->horizontalScale = this->viewPort.w / SCREEN_WIDTH;
    this->verticalScale = this->viewPort.h / SCREEN_HEIGHT;
}

void App::setupInitialState() {
    player.x = ((int) floor(SCREEN_WIDTH / 2) * this->horizontalScale);
    player.y = ((int) ceil(SCREEN_HEIGHT / 2) * this->verticalScale);
    player.w = this->horizontalScale;
    player.h = this->verticalScale;
}