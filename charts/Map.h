#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <exception>
#include <string>
#include <iostream>
#include <fstream>
#include "Objet.h"
#include "Province.h"
#include <SDL2/SDL.h>

class Map
{
private:
    SDL_Rect src, dest;
    SDL_Renderer* renderer;

    int d_val_d_aost, d_diemont, d_ligura, d_lombardia, d_trentin, d_venetie, d_julienne, d_romagne, d_toscane, d_ombrie;
    int d_marches, d_abruzzes, d_latium, d_molise, d_campania, d_pouilles, d_brasilicates, d_calibre, d_sicile, d_sardaigne;

    int _map[25][25];
    int _map_region[25][25];

public:
    Map(SDL_Renderer* ren);
    void lireMap();
    void lireDonnee();
    void loadMap(int arr[25][25]);
    void drawMap();
    void drawMapRegion();
    void lireValeur();
    void clearMap();
    void clearMapRegion();

    int chercher_region(/*SDL_Rect rect*/ int lgn, int col, SDL_Renderer *ren);
    ~Map() {}
};
#endif
