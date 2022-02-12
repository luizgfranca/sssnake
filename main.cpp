#include <SDL2/SDL.h>
#include "app.h"

int main(int argc, char *argv[]) {

    auto app = new App();
    app->init();
    
    return 0;
}
