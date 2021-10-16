#include <SDL2/SDL.h>
#include "app.h"
#include "SDLEventHandler.h"

class EventResolver {

    App *app;
    
    SDLEventHandler *sdlEventHandler;

    SDL_Event sdlEvent;

public:
    EventResolver(App *app);
    void resolveEvents();

};