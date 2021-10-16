#include "SDLEventHandler.h"
#include "app.h"

void SDLEventHandler::handle(App *app, SDL_Event e) {

    if(e.type == SDL_QUIT) {
        this->handleCloseEvent(app);
    }

}

void SDLEventHandler::handleCloseEvent(App *app) {

    app->setIsRunning(false);

}