#include <exception>
#include <string>
#include <iostream>
#include <SDL2/SDL.h>

#include "Fonction.h"


int main( int argc, char * argv[] )
{
    Fonction *fonction = nullptr;
    fonction = new Fonction();
    fonction->init("Covid-19", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 650, 650);

    //rendre le programme lisse
    const int FPS = 60;
    const int frameDelay =1000/FPS;

    Uint32 frameStart;
    int frameTime;

    while(fonction->running())
    {
        frameStart = SDL_GetTicks();

        //le jeu
        fonction->handleEvents();
        fonction->update();
        fonction->funct_renderer();

        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime)
            SDL_Delay(frameDelay-frameTime);
    }
    fonction->clean();
    return 0;
}
