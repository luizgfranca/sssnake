#include <SDL2/SDL.h>

class App;

class App 
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;

    bool shouldClose;

    void startEventLoop();
    void eventLoop();
    void createWindow();

    public: 
        void init();

};