#include "GameLogicProcessor.h"
#include "event.h"

GameLogicProcessor::GameLogicProcessor(App *context) {
    this->context = context;
    this->shouldIncrementSnakeSize = false;
}

void GameLogicProcessor::process() {
    this->context->player->step(this->shouldIncrementSnakeSize);

    if( this->wasFoodCaptured() ) {
        context->throwEvent(Event::CAPTURED);
    }

    if( this->hasPlayerSelfEaten() )
        context->throwEvent(Event::GAME_OVER);

    this->shouldIncrementSnakeSize = false;
}


bool GameLogicProcessor::wasFoodCaptured() {
    auto head = this->context->player->getHeadPosition();
    auto foodPosition = this->context->food->getPosition();

    return (head.x == foodPosition.x && head.y == foodPosition.y);
}

bool GameLogicProcessor::hasPlayerSelfEaten() {
    return (
        this->context->player->isPositionInsideBody(
            this->context->player->getHeadPosition()
        )
    );
}

void GameLogicProcessor::incrementSnakeSize() {
    this->shouldIncrementSnakeSize = true;
}