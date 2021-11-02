#pragma once

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

    int headX;
    int headY;

    Direction direction;

    int platformWidth;
    int platformHeight;

public:
    Snake(int platformWidth, int platformHeight);

    void setHeadPosition(int x, int y);
    Coordinates getHeadPosition();
    void step();
    void changeDirection(Direction direction);
};

