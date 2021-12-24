#pragma once
#include <queue>
#include <vector>

class Snake;

typedef struct coordinates
{
    int x;
    int y;
} Coordinates;

enum class Direction {
    UP, 
    DOWN, 
    LEFT,
    RIGHT
};

class Snake {

    std::queue<Coordinates> *body;
    Direction direction;
    Coordinates trail;
    std::vector<Coordinates> *initialSnapshot;

    int platformWidth;
    int platformHeight;

    int size;

    void createBody(int headX, int headY);
public:
    Snake(int size, int platformWidth, int platformHeight);

    void setHeadPosition(int x, int y);
    
    Coordinates getHeadPosition();
    Coordinates getTrail();
    std::vector<Coordinates> *getInitialPosition();
    int getLength();
    void step();
    void changeDirection(Direction direction);
};

