#include <SDL2/SDL.h>
#include "app.h"
#include "SDLEventHandler.h"
#include "GameEventHandler.h"

class EventResolver {

    App *app;
    
    SDLEventHandler *sdlEventHandler;
    GameEventHandler *gameEventHandler;

    SDL_Event sdlEvent;

    void handleSDLEvents();
    bool hasGameEvent();
    void handleGameEvents();

public:
    EventResolver(App *app);
    void resolveEvents();

};