#include "SDLEventHandler.h"
#include "app.h"

void SDLEventHandler::handle(App *app, SDL_Event e) {

    switch (e.type)
    {
    case SDL_QUIT:
        this->handleCloseEvent(app);
        break;
    
    case SDL_KEYDOWN:
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
        case SDLK_DOWN:
        case SDLK_RIGHT:
        case SDLK_LEFT:
            app->throwEvent( 
                this->convertKeyIntoGameEvent(e.key.keysym.sym) 
            );
            break;
        
        default:
            break;
        }

    default:
        break;
    }



    if(e.type == SDL_QUIT) {
        this->handleCloseEvent(app);
    }

}

void SDLEventHandler::handleCloseEvent(App *app) {

    app->setIsRunning(false);

}

Event SDLEventHandler::convertKeyIntoGameEvent(SDL_Keycode key) {

    switch (key)
    {

    case SDLK_UP:
        return Event::DIRECTION_UP;
        break;

    case SDLK_DOWN:
        return Event::DIRECTION_DOWN;
        break;

    case SDLK_RIGHT:
        return Event::DIRECTION_RIGHT;
        break;

    case SDLK_LEFT:
        return Event::DIRECTION_LEFT;
        break;
    
    default:
        throw "[SDLEventHandler::convertKeyIntoGameEvent] No command found";
        break;
    }

}