#include "Renderer.h"
#include "displayConfig.cpp"

Renderer::Renderer(SDL_Renderer *renderer) {
    this->renderer = renderer;


    

}

void Renderer::renderPlayer(SDL_Rect player) {
    //SDL_Log("Renderer::renderPlayer %d %d %d %d", player.w, player.h, player.x, player.y);
    reset(); //just until i implement a partial update method
    
    SDL_SetRenderDrawColor(
        this->renderer,
        PLAYER_COLOR_R, 
        PLAYER_COLOR_G, 
        PLAYER_COLOR_B, 
        PLAYER_COLOR_A
    );
    
    SDL_RenderFillRect(this->renderer, &player);
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