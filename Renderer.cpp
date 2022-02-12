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

SDL_Rect Renderer::createUnitRect(Coordinates coordinates) {
    SDL_Rect rect;
    
    rect.x = coordinates.x * this->horizontalScale;
    rect.y = coordinates.y * this->verticalScale;
    rect.w = this->horizontalScale;
    rect.h = this->verticalScale;

    return rect;
} 

void Renderer::renderUnit(
    Coordinates coord, 
    int color_r, 
    int color_g, 
    int color_b, 
    int color_a
) {
    auto rect = this->createUnitRect(coord);

    SDL_SetRenderDrawColor(
        this->renderer,
        color_r, 
        color_g, 
        color_b, 
        color_a
    );

    SDL_RenderFillRect(this->renderer, &rect);
}

void Renderer::renderPlayerUnit(Coordinates unit) {
    this->renderUnit(
        unit,
        PLAYER_COLOR_R, 
        PLAYER_COLOR_G, 
        PLAYER_COLOR_B, 
        PLAYER_COLOR_A
    );
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

    this->renderUnit(
        trail,
        BACKGROUND_COLOR_R, 
        BACKGROUND_COLOR_G, 
        BACKGROUND_COLOR_B, 
        BACKGROUND_COLOR_A
    );
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

void Renderer::renderFood(Food *food) {
    auto coordinates = food->getPosition();

    this->renderUnit(
        coordinates,
        FOOD_COLOR_R,
        FOOD_COLOR_G,
        FOOD_COLOR_B,
        FOOD_COLOR_A
    );
}