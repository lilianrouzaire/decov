#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

#include <exception>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <SDL2/SDL.h>


using namespace std;

struct coordonne
{
    int lgn;
    int col;
};

class Fonction
{
    private:
        bool isRunning, region;
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Rect dest;
        vector<coordonne> liste;
    public:
        Fonction();
        void init(const char* title, int xpos, int ypos, int width, int height);
        void handleEvents();
        void update();
        void funct_renderer();
        void clean();
        bool running();

        virtual ~Fonction();
};

#endif // FONCTION_H_INCLUDED
