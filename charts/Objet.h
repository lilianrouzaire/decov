#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED

#include <exception>
#include <string>
#include <iostream>
#include <SDL2/SDL.h>

class Objet
{
private:
    SDL_Texture* ObjImage;
    SDL_Rect srcR, destR;
    SDL_Renderer* renderer;
    int xpos, ypos;

public:
    Objet(const char* filename, SDL_Renderer *ren, int x, int y);
    void update(int dest_w, int dest_h);
    void func_renderer();
    ~Objet() {}
};

#endif // OBJET_H_INCLUDED
