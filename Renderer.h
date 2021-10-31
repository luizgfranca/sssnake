#include <SDL2/SDL.h>
#include "Snake.h"

class Renderer;

class Renderer {

    SDL_Renderer *renderer;
    SDL_Rect viewPort;

    int width;
    int height;

    int horizontalScale;
    int verticalScale;

public: 
    Renderer(SDL_Renderer *renderer);
    void setScaling(int width, int height);
    void renderPlayer(Snake *player);
    void reset();
};