#include "Renderengine.hpp"
#include <iostream>

int main() 
{
    RenderEngine renderer = RenderEngine();
    if (renderer.init()) {
        return -1;
    }

    renderer.loop();
    
    return 0;
}