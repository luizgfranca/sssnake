#pragma once
#include <queue>
#include <vector>
#include "coordinates.h"

class Snake;



enum class Direction {
    UP, 
    DOWN, 
    LEFT,
    RIGHT
};

class Snake {

    std::vector<Coordinates> *body;
    Direction newDirection;
    Direction direction;
    Coordinates trail;
    std::vector<Coordinates> *initialSnapshot;

    int platformWidth;
    int platformHeight;

    int size;

    void createBody(int headX, int headY);
    void updateHead(Coordinates coord);
    void popTail();
    bool handleDirectionInversion();
public:
    Snake(int size, int platformWidth, int platformHeight);

    void setHeadPosition(int x, int y);
    
    Coordinates getHeadPosition();
    Coordinates getTrail();
    std::vector<Coordinates> *getInitialPosition();
    
    int getLength();
    bool isPositionInsideBody(Coordinates coord);

    void step(bool shouldClearTrail);
    void changeDirection(Direction direction);
};

