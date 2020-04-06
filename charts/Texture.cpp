#include "Texture.h"


SDL_Texture* Texture::LoadTexture(const char* filename, SDL_Renderer* ren)
{
    SDL_Surface *tmpSurface = SDL_LoadBMP(filename);
    SDL_Texture *image = SDL_CreateTextureFromSurface(ren, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    return image;
}

