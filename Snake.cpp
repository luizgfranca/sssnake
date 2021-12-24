#include "Snake.h"
#include <SDL2/SDL.h>

Snake::Snake(int size, int platformWidth, int platformHeight) {
    this->platformWidth = platformWidth;
    this->platformHeight = platformHeight;
    this->size = size;

    this->body = new std::queue<Coordinates>();
    this->initialSnapshot = new std::vector<Coordinates>();

    this->direction = Direction::RIGHT;

    this->trail = {-1, -1};
}
void Snake::setHeadPosition(int x, int y) {
    int headX = (x < platformWidth) ? x : 0;
    int headY = (y < platformHeight) ? y : 0;

    this->createBody(headX, headY);
}

void Snake::createBody(int headX, int headY) {
    int x = headX;
    int y = headY;

    this->initialSnapshot->push_back({headX, headY});

    for(int i = 0; i <= this->size - 2; i ++) {
        switch (this->direction)
        {
        case Direction::RIGHT:
            x --;
            break;
        
        case Direction::LEFT:
            x ++;
            break;

        case Direction::UP:
            y ++;
            break;

        case Direction::DOWN:
            y --;
            break;

        default:
            break;
        }

        this->initialSnapshot->push_back({x, y});
    }

    for(int i = this->initialSnapshot->size() - 1; i > 0; i --) {
        this->body->push({
            this->initialSnapshot->at(i).x, 
            this->initialSnapshot->at(i).y
        });
    }

    this->body->push({headX, headY});

}

Coordinates Snake::getHeadPosition() {
    Coordinates coord;

    if(this->body->size() == 0)
        return {-1, -1};

    coord.x = this->body->back().x;
    coord.y = this->body->back().y;
    return coord;
}

void Snake::step() {
    int headX = this->getHeadPosition().x;
    int headY = this->getHeadPosition().y;

    switch (this->direction)
    {
    case Direction::UP:
        headY --;
        if(headY < 0)
            headY = this->platformHeight - 1;
            
        break;
    
    case Direction::DOWN:
        headY ++;
        if(headY > this->platformHeight)
            headY = 0;
            
        break;

    case Direction::RIGHT:
        headX ++;
        if(headX > this->platformWidth)
            headX = 0;
        break;

    case Direction::LEFT:
        headX --;
        if(headX < 0) 
            headX = this->platformWidth - 1;
        break;
    
    default:
        break;
    }

    this->body->push({headX, headY});

    this->trail = this->body->front();
    this->body->pop();
}

void Snake::changeDirection(Direction direction) {
    this->direction = direction;
}

Coordinates Snake::getTrail() {
    return this->trail;
}

int Snake::getLength() {
    return this->body->size();
}

std::vector<Coordinates> *Snake::getInitialPosition() {
    return this->initialSnapshot;
}