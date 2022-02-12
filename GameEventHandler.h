#pragma once

#include <queue>
#include "app.h"

class GameEventHandler;

class GameEventHandler {

public:
    void handle(App *app, Event e);
};