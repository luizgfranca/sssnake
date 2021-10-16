#include "EventResolver.h"

EventResolver::EventResolver(App *app) {
    this->app = app;
    this->sdlEventHandler = new SDLEventHandler();
}

void EventResolver::resolveEvents() {

    if( SDL_PollEvent(&this->sdlEvent) ) {
        this->sdlEventHandler->handle(this->app, this->sdlEvent);
    }

}