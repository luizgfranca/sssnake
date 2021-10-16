#include <SDL2/SDL.h>

class Renderer;

class Renderer {

    SDL_Renderer *renderer;

public: 
    Renderer(SDL_Renderer *renderer);
    void renderPlayer(SDL_Rect player);
    void reset();
};