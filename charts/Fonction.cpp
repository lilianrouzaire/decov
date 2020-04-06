#include "Fonction.h"
#include "Objet.h"
#include "Map.h"
#include "Texture.h"



SDL_Texture *image;
Objet* italie;
Objet* italie_legende;
Objet* provence;
Objet* province_legende;
Map* _map;

Fonction::Fonction()
{
    dest.h = dest.w = 26;
    region = false;
}

void Fonction::init(const char* title, int xpos, int ypos, int width, int height)
{
    if(SDL_Init(SDL_INIT_EVERYTHING)==0)
    {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, 0);

        renderer = SDL_CreateRenderer(window,-1,0);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        isRunning = true;
    }
    else
        isRunning = false;

    //mettre les images
    //italie = new Objet("province/venetie.bmp", renderer, 0,0);
    italie = new Objet("italie_region.bmp", renderer, 0,0);
    italie_legende = new Objet("legende_r.bmp", renderer, 0,624);

    _map = new Map(renderer);

}
void Fonction::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    int x, y, noProvince;

    ofstream venetie;
    switch(event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    case SDL_MOUSEBUTTONDOWN:
            /** CECI SERT à TROUVER LES COORDONNEES DES REGIONS */

            /*if(event.button.button == SDL_BUTTON_RIGHT)
            {
                venetie.open("demonstration.txt" );
                if(venetie)
                {
                    for(size_t i=0; i<liste.size(); i++)
                        venetie << liste[i].lgn << " " << liste[i].col << endl;
                }
            }*/

            /** ET CECI PERMET D'AFFICHER LA REGION CLICQUéE*/
            for(int i=0; i<25; i++)
            {
                if(event.button.x >= i*26 && event.button.x < (i+1)*26)
                {
                    for(int j=0; j<25; j++)
                        if(event.button.y >= j*26 && event.button.y < (j+1)*26)
                        {
                            /** CECI SERT à TROUVER LES COORDONNEES DES REGIONS */
                            /*
                            coordonne c;
                            c.lgn = i;
                            c.col = j;
                                liste.push_back(c);*/
                            /** COMMENTAIRE */
                            cout << "{" << j << ", " << i << "}" << endl;

                            if(region == false)
                            {
                                noProvince = _map->chercher_region(j, i, renderer);
                                SDL_RenderClear(renderer);
                                if(noProvince == 5)
                                {
                                    _map->clearMap();
                                    provence = new Objet("province/venetie.bmp", renderer, 0,0);
                                    province_legende = new Objet("venetie/legende_b.bmp", renderer, 0, 624);
                                    region = true;
                                }
                            }
                            else
                            {
                                _map->clearMapRegion();
                                region = false;
                                _map->lireDonnee();
                            }
                            dest.x = i*26;
                            dest.y =j*26;
                            break;
                        }
                    break;
                }
            }
            break;
    default:
        break;
    }
}
void Fonction::update()
{
    if(region == false)
    {
        italie->update(650, 650);
        italie_legende ->update(130, 13);
    }
    else
    {
        provence->update(650, 650);
        province_legende->update(130, 13);
    }
}

void Fonction::funct_renderer()
{
    SDL_RenderClear(renderer);

    if(region == false)
    {
       italie->func_renderer();
       italie_legende->func_renderer();
        _map->drawMap();
    }
    else
    {
        provence->func_renderer();
        province_legende->func_renderer();
        _map->drawMapRegion();
    }

   SDL_RenderPresent(renderer);
}
void Fonction::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_QUIT;
}
bool Fonction::running()
{
    return isRunning;
}

Fonction::~Fonction()
{}
