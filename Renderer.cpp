#include "Renderer.h"
#include "displayConfig.cpp"

Renderer::Renderer(SDL_Renderer *renderer) {
    this->renderer = renderer;
    SDL_RenderGetViewport(this->renderer, &this->viewPort);
}

void Renderer::renderPlayer(Snake *player) {
    reset(); //just until i implement a partial update method
    
    SDL_Rect headRect;
    auto coordinates = player->getHeadPosition();
    headRect.x = coordinates.x * this->horizontalScale;
    headRect.y = coordinates.y * this->verticalScale;
    headRect.w = this->horizontalScale;
    headRect.h = this->verticalScale;

    SDL_SetRenderDrawColor(
        this->renderer,
        PLAYER_COLOR_R, 
        PLAYER_COLOR_G, 
        PLAYER_COLOR_B, 
        PLAYER_COLOR_A
    );
    
    SDL_RenderFillRect(this->renderer, &headRect);
}

void Renderer::setScaling(int width, int height) {
    this->width = width;
    this->height = height;

    this->horizontalScale = this->viewPort.w / width;
    this->verticalScale = this->viewPort.h / height;
}

void Renderer::reset() {
    SDL_SetRenderDrawColor(
        this->renderer,
        BACKGROUND_COLOR_R, 
        BACKGROUND_COLOR_G, 
        BACKGROUND_COLOR_B, 
        BACKGROUND_COLOR_A
    );

    SDL_RenderClear(this->renderer);
}