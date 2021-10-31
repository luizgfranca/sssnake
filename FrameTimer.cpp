#include "FrameTimer.h"

void FrameTimer::start(unsigned int ms) {
    this->duration = ms;
    this->msStart = SDL_GetTicks();
}

bool FrameTimer::isDone() {
    return (SDL_GetTicks() - msStart) >= this->duration;
}