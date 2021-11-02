#include <SDL2/SDL.h>
#include "app.h"

class SDLEventHandler;

class SDLEventHandler {

private:
    void handleCloseEvent(App *app);
    Event convertKeyIntoGameEvent(SDL_Keycode key);

public:
    void handle(App *app, SDL_Event e);

};