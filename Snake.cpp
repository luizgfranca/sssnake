#include "Snake.h"
#include <SDL2/SDL.h>

Snake::Snake(int platformWidth, int platformHeight) {
    this->platformWidth = platformWidth;
    this->platformHeight = platformHeight;
    this->headX = 0;
    this->headY = 0;
    this->direction = Direction::RIGHT;
}
void Snake::setHeadPosition(int x, int y) {
    this->headX = (x < platformWidth) ? x : 0;
    this->headY = (y < platformHeight) ? y : 0;
}

Coordinates Snake::getHeadPosition() {
    Coordinates coord;
    coord.x = this->headX;
    coord.y = this->headY;
    return coord;
}

void Snake::step() {

    switch (this->direction)
    {
    case Direction::UP:
        this->headY --;
        if(this->headY < 0)
            this->headY = this->platformHeight - 1;
            
        break;
    
    case Direction::DOWN:
        this->headY ++;
        if(headY > this->platformHeight)
            this->headY = 0;
            
        break;

    case Direction::RIGHT:
        this->headX ++;
        if(this->headX > this->platformWidth)
            this->headX = 0;
        break;

    case Direction::LEFT:
        this->headX --;
        if(this->headX < 0) 
            this->headX = this->platformWidth - 1;
        break;
    
    default:
        break;
    }

}

void Snake::changeDirection(Direction direction) {
    this->direction = direction;
}
