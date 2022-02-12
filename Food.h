#pragma once
#include "coordinates.h"
#include "Snake.h"

class Food;

class Food {

    Coordinates position;
    int platformWidth;
    int platformHeight;

public:

    Food(int platformWidth, int platformHeight);

    void generate(Snake *player);
    Coordinates getPosition();
};