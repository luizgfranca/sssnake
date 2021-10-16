#include <SDL2/SDL.h>
#include "app.h"

class SDLEventHandler;

class SDLEventHandler {

private:
    void handleCloseEvent(App *app);

public:
    void handle(App *app, SDL_Event e);

};