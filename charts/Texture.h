#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

#include <exception>
#include <string>
#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

class Texture
{
public:
    static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* ren);
    //static void Draw(SDL_Texture* image, SDL_Rect src, SDL_Rect dest, SDL_Renderer* ren);
};



#endif // TEXTURE_H_INCLUDED
