#include <SDL2/SDL.h>
#include "Snake.h"
#include <vector>

class Renderer;

class Renderer {

    SDL_Renderer *renderer;
    SDL_Rect viewPort;

    int width;
    int height;

    int horizontalScale;
    int verticalScale;

    bool isFirstRun;

    SDL_Rect createBodyUnitRect(Coordinates coordinates);
    void renderPlayerUnit(Coordinates unit);

    void renderHead(Snake *player);
    void renderFullBody(Snake *player);
    void cleanTrail(Snake *player);

public: 
    Renderer(SDL_Renderer *renderer);
    void setScaling(int width, int height);
    void renderPlayer(Snake *player);
    void reset();
    void doPartialRender(Snake *player);
    void doFullRender(Snake *player);
};