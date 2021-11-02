#include "GameEventHandler.h"
#include "Snake.h"

void GameEventHandler::handle(App *app, Event e) {
    switch (e)
    {
    case Event::DIRECTION_UP:
        app->player->changeDirection(Direction::UP);
        break;
    
    case Event::DIRECTION_DOWN :
        app->player->changeDirection(Direction::DOWN);
        break;
    
    case Event::DIRECTION_RIGHT :
        app->player->changeDirection(Direction::RIGHT);
        break;
    
    case Event::DIRECTION_LEFT:
        app->player->changeDirection(Direction::LEFT);
        break;
    
    default:
        break;
    }
}