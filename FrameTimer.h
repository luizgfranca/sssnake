#include <SDL2/SDL.h>

class FrameTimer;

class FrameTimer {

    int msStart;
    unsigned int duration;

public:
    void start(unsigned int ms);
    bool isDone();
};