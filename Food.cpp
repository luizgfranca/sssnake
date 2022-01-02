#include "Food.h"
#include "Snake.h"
#include <stdlib.h>
#include <ctime>

Food::Food(int platformWidth, int platformHeight) {
    this->platformWidth = platformWidth;
    this->platformHeight = platformHeight;
}

void Food::generate(Snake *player) {
    Coordinates position = {-1, -1};

    while (
        (position.x == -1 && position.y == -1) || 
        player->isPositionInsideBody(position) 
    ) {
        srand((unsigned int) time(0));
        position.x = rand() % this->platformWidth;
        position.y = rand() % this->platformHeight;
    }

    this->position = position;

}

Coordinates Food::getPosition() {
    return this->position;
}