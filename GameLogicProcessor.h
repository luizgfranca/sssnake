#pragma once
#include "app.h"

class App;
class GameLogicProcessor;

class GameLogicProcessor {
    App *context;

    bool shouldIncrementSnakeSize;

    bool wasFoodCaptured();

    public: 
        GameLogicProcessor(App *context);
        void incrementSnakeSize();
        void process();
};
