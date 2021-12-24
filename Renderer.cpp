#include "Renderer.h"
#include "displayConfig.cpp"

Renderer::Renderer(SDL_Renderer *renderer) {
    this->renderer = renderer;
    SDL_RenderGetViewport(this->renderer, &this->viewPort);
    this->isFirstRun = true;
}

void Renderer::renderPlayer(Snake *player) {
    this->renderHead(player);

    if(this->isFirstRun)
        this->renderFullBody(player);

    this->cleanTrail(player);

    isFirstRun = false;
}

SDL_Rect Renderer::createBodyUnitRect(Coordinates coordinates) {
    SDL_Rect rect;
    
    rect.x = coordinates.x * this->horizontalScale;
    rect.y = coordinates.y * this->verticalScale;
    rect.w = this->horizontalScale;
    rect.h = this->verticalScale;

    return rect;
} 

void Renderer::renderPlayerUnit(Coordinates unit) {
    auto rect = this->createBodyUnitRect(unit);

    SDL_SetRenderDrawColor(
        this->renderer,
        PLAYER_COLOR_R, 
        PLAYER_COLOR_G, 
        PLAYER_COLOR_B, 
        PLAYER_COLOR_A
    );
    
    SDL_RenderFillRect(this->renderer, &rect);
}

void Renderer::renderHead(Snake *player) {

    auto coordinates = player->getHeadPosition();
    if(coordinates.x == -1 && coordinates.y == -1)
        return;

    this->renderPlayerUnit(coordinates);
}

void Renderer::renderFullBody(Snake *player) {

    auto initialPosition = player->getInitialPosition();

    for(long unsigned int i = 0; i < initialPosition->size(); i ++) {
        Coordinates position = initialPosition->at(i);
        this->renderPlayerUnit(position);
    }

}

void Renderer::cleanTrail(Snake *player) {
    auto trail = player->getTrail();
    if(trail.x == -1 && trail.y == -1)
        return;

    auto rect = this->createBodyUnitRect(trail);

    SDL_SetRenderDrawColor(
        this->renderer,
        BACKGROUND_COLOR_R, 
        BACKGROUND_COLOR_G, 
        BACKGROUND_COLOR_B, 
        BACKGROUND_COLOR_A
    );
    
    SDL_RenderFillRect(this->renderer, &rect);

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