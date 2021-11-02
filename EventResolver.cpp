#include "EventResolver.h"

EventResolver::EventResolver(App *app) {
    this->app = app;
    this->sdlEventHandler = new SDLEventHandler();
    this->gameEventHandler = new GameEventHandler();
}

void EventResolver::resolveEvents() {
    this->handleSDLEvents();
    this->handleGameEvents();
}

void EventResolver::handleSDLEvents() {
    if( SDL_PollEvent(&this->sdlEvent) ) {
        this->sdlEventHandler->handle(this->app, this->sdlEvent);
    }
}

bool EventResolver::hasGameEvent() {
    return !this->app->eventQueue->empty();
}

void EventResolver::handleGameEvents() {
    while (this->hasGameEvent())
    {
        this->gameEventHandler->handle(
            this->app, 
            this->app->eventQueue->back()
        );

        this->app->eventQueue->pop();
    }
    
}