#pragma once

class Snake;

typedef struct coordinates
{
    int x;
    int y;
} Coordinates;

class Snake {

    int headX;
    int headY;

    int platformWidth;
    int platformHeight;

public:
    Snake(int platformWidth, int platformHeight);

    void setHeadPosition(int x, int y);
    Coordinates getHeadPosition();
    void step();
};

