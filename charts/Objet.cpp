#include "Objet.h"
#include "Texture.h"


Objet::Objet(const char* filename, SDL_Renderer *ren, int x, int y)
{
    renderer = ren;
    ObjImage = Texture::LoadTexture(filename, ren);
    xpos = x;
    ypos = y;
}
void Objet::update(int dest_w, int dest_h)
{
    srcR.h = 200;
    srcR.w = 100;
    srcR.x = 0;
    srcR.y = 0;

    destR.x = xpos;
    destR.y = ypos;
    /*destR.w = 650;
    destR.h = 650;*/
    destR.w = dest_w;
    destR.h = dest_h;
}
void Objet::func_renderer()
{
    SDL_RenderCopy(renderer, ObjImage, NULL, &destR);
}
