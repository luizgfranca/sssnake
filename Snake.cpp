#include "Snake.h"

Snake::Snake(int platformWidth, int platformHeight) {
    this->platformWidth = platformWidth;
    this->platformHeight = platformHeight;
    this->headX = 0;
    this->headY = 0;
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
    this->headX ++;

    if(this->headX >= platformWidth)
        this->headX = 0;

    if(this->headY >= platformHeight) 
        this->headY = 0;
}