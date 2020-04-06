#include "Map.h"
#include "Texture.h"
#include "Nom.h"
#define NOTHING 100

Map::Map(SDL_Renderer* ren)
{
    renderer = ren;

    //lireMap();
    //lireValeur();
    lireDonnee();

    src.x =src.y =0;
    src.w = dest.w = 26;
    src.h = dest.h = 26;
    dest.x = dest.y = 0;
}
void Map::loadMap(int arr[25][25])
{
    for(int ligne=0; ligne<25;ligne++)
        for(int colonne=0; colonne<25; colonne++)
            _map[ligne][colonne]=arr[ligne][colonne];
}
void Map::lireDonnee()
{
    for(int ligne=0; ligne<25;ligne++)
        for(int colonne=0; colonne<25; colonne++)
            _map[ligne][colonne]=0;

    ifstream donnee;
    donnee.open("donnes.txt");
    donnee >>  d_val_d_aost;
    donnee >> d_diemont;
    donnee >> d_ligura;
    donnee >> d_lombardia;
    donnee >> d_trentin;
    donnee >> d_venetie;
    donnee >> d_julienne;
    donnee >> d_romagne;
    donnee >> d_toscane;
    donnee >> d_ombrie;
    donnee >> d_marches;
    donnee >> d_abruzzes;
    donnee >> d_latium;
    donnee >> d_molise;
    donnee >> d_campania;
    donnee >> d_pouilles;
    donnee >> d_brasilicates;
    donnee >> d_calibre;
    donnee >> d_sicile;
    donnee >> d_sardaigne;

    //0
    for(int ind=0; ind<2; ind++)
        _map[val_d_Aoste[ind][0]][val_d_Aoste[ind][1]]= d_val_d_aost ;

    for(int ind=0; ind<17; ind++)
        _map[diemont[ind][0]][diemont[ind][1]]= d_diemont;
    //2
    for(int ind=0; ind<5; ind++)
        _map[liguria[ind][0]][liguria[ind][1]]= d_ligura;
    //3
    for(int ind=0; ind<12; ind++)
        _map[lombarie[ind][0]][lombarie[ind][1]]=d_lombardia ;

    for(int ind=0; ind<6; ind++)
        _map[trentin[ind][0]][trentin[ind][1]]=d_trentin ;

    for(int ind=0; ind<9; ind++)
        _map[venetie[ind][0]][venetie[ind][1]]=d_venetie ;

    for(int ind=0; ind<7; ind++)
        _map[v_julienne[ind][0]][v_julienne[ind][1]]=d_julienne;

    for(int ind=0; ind<15; ind++)
        _map[romagne[ind][0]][romagne[ind][1]]= d_romagne;

    for(int ind=0; ind<14; ind++)
        _map[toscane[ind][0]][toscane[ind][1]]=d_toscane ;

    for(int ind=0; ind<5; ind++)
        _map[ombrie[ind][0]][ombrie[ind][1]]=d_ombrie ;

    for(int ind=0; ind<5; ind++)
        _map[marches[ind][0]][marches[ind][1]]=d_marches ;

    for(int ind=0; ind<7; ind++)
        _map[abruzzes[ind][0]][abruzzes[ind][1]]= d_abruzzes;

    for(int ind=0; ind<8; ind++)
        _map[latium[ind][0]][latium[ind][1]]= d_latium;

    for(int ind=0; ind<4; ind++)
        _map[molise[ind][0]][molise[ind][1]]= d_molise;

    for(int ind=0; ind<9; ind++)
        _map[campania[ind][0]][campania[ind][1]]= d_campania;

    for(int ind=0; ind<14; ind++)
        _map[pouilles[ind][0]][pouilles[ind][1]]=d_pouilles ;

    for(int ind=0; ind<10; ind++)
        _map[brasilicate[ind][0]][brasilicate[ind][1]]=d_brasilicates ;

    for(int ind=0; ind<12; ind++)
        _map[calibre[ind][0]][calibre[ind][1]]=d_calibre;

    for(int ind=0; ind<19; ind++)
        _map[sicile[ind][0]][sicile[ind][1]]=d_sicile;

    for(int ind=0; ind<13; ind++)
        _map[sardaigne[ind][0]][sardaigne[ind][1]]=d_sardaigne;
}
void Map::lireMap()
{
    ifstream terrain;
    terrain.open("terrain.txt");
    for(int ligne=0; ligne<25;ligne++)
        for(int colonne=0; colonne<25; colonne++)
            terrain >> _map[ligne][colonne];
}
void Map::drawMap()
{
    int type=0;
    for(int ligne=0; ligne<25;ligne++)
        for(int colonne=0; colonne<25; colonne++)
        {
            dest.x = colonne*26;
            dest.y = ligne*26;
            type=_map[ligne][colonne];
            SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, type*25);
            SDL_RenderFillRect(renderer, &dest);
        }
}
void Map::drawMapRegion()
{
    int type=0;
    for(int ligne=0; ligne<25;ligne++)
        for(int colonne=0; colonne<25; colonne++)
        {
            dest.x = colonne*26;
            dest.y = ligne*26;
            type=_map_region[ligne][colonne];
            SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, type*10);
            SDL_RenderFillRect(renderer, &dest);
        }
}
void Map::lireValeur()
{
    int compteur = 0;
    int liste[20];
    double valeur_lu;
    ifstream valeur;
    valeur.open("valeur.txt");

    while(compteur < 20)
    {
        valeur >> valeur_lu;
        for(int i=0; i<100; i++)
        if(valeur_lu >= i*0.01 && valeur_lu < (i+1)*0.01)
        {
            //cout << compteur << " valeur_lu" <<valeur_lu << " " << i << endl;
            liste[compteur] = i;
            break;
        }
        compteur++;
    }

    ofstream donnee;
    donnee.open("donnes.txt" );
    if(donnee)
        for(int i = 0; i<20; i++)
            donnee << liste[i] << endl;
}

int Map::chercher_region(int lgn, int col, SDL_Renderer *ren)
{
    for(int ind=0; ind<2; ind++)
    {
        if(lgn == val_d_Aoste[ind][0] && col == val_d_Aoste[ind][1])
            cout << 0 << endl;
    }
    //1
    for(int ind=0; ind<17; ind++)
    {
        if(lgn == diemont[ind][0] && col == diemont[ind][1])
            cout << 1 << endl;
    }
    //2
    for(int ind=0; ind<5; ind++)
    {
        if(lgn== liguria[ind][0] && col == liguria[ind][1])
            cout << 2 << endl;
    }
    //3
    for(int ind=0; ind<12; ind++)
    {
        if(lgn == lombarie[ind][0] && col == lombarie[ind][1])
            cout << 3 << endl;
    }

    for(int ind=0; ind<6; ind++)
    {
        if(lgn == trentin[ind][0] && col == trentin[ind][1])
            cout << 4 << endl;
    }
    for(int ind=0; ind<9; ind++)
    {
        SDL_RenderClear(ren);
        if(lgn == venetie[ind][0] && col == venetie[ind][1])
        {
            loadVenetie(lgn, col, _map_region, _map);
            cout << 5 << endl;
            return 5;
        }
    }
    for(int ind=0; ind<7; ind++)
    {
        if(lgn == v_julienne[ind][0] && col== v_julienne[ind][1])
            cout << 6 << endl;
    }
    for(int ind=0; ind<15; ind++)
    {
        if(lgn == romagne[ind][0] && col == romagne[ind][1])
            cout << 7 << endl;
    }
    for(int ind=0; ind<14; ind++)
    {
        if(lgn == toscane[ind][0] && col == toscane[ind][1])
            cout << 8 << endl;
    }
    for(int ind=0; ind<5; ind++)
    {
        if(lgn == ombrie[ind][0] && col == ombrie[ind][1])
            cout << 9 << endl;
    }
    for(int ind=0; ind<5; ind++)
    {
        if(lgn== marches[ind][0] && col == marches[ind][1])
            cout << 10 << endl;
    }
    for(int ind=0; ind<7; ind++)
    {
        if(lgn == abruzzes[ind][0] && col == abruzzes[ind][1])
            cout << 11 << endl;
    }
    for(int ind=0; ind<8; ind++)
    {
        if(lgn == latium[ind][0] && col == latium[ind][1])
            cout << 12 << endl;
    }
    for(int ind=0; ind<4; ind++)
    {
        if(lgn == molise[ind][0] && col== molise[ind][1])
            cout << 13 << endl;
    }
    for(int ind=0; ind<9; ind++)
    {
        if(lgn == campania[ind][0] && col == campania[ind][1])
            cout << 14 << endl;
    }
    for(int ind=0; ind<14; ind++)
    {
        if(lgn == pouilles[ind][0] && col ==pouilles[ind][1])
            cout << 15 << endl;
    }
    for(int ind=0; ind<10; ind++)
    {
        if(lgn == brasilicate[ind][0] && col == brasilicate[ind][1])
            cout << 16 << endl;
    }
    for(int ind=0; ind<12; ind++)
    {
        if(lgn == calibre[ind][0] && col == calibre[ind][1])
            cout << 17 << endl;
    }
    for(int ind=0; ind<19; ind++)
    {
        if(lgn == sicile[ind][0] && col == sicile[ind][1])
            cout << 18 << endl;
    }
    for(int ind=0; ind<13; ind++)
    {
        if(lgn == sardaigne[ind][0] && col == sardaigne[ind][1])
            cout << 19 << endl;
    }
    return NOTHING;
}
void Map::clearMap()
{
    for(int ligne=0; ligne<25;ligne++)
        for(int colonne=0; colonne<25; colonne++)
            _map[ligne][colonne]=0;


}
void Map::clearMapRegion()
{
    for(int ligne=0; ligne<25;ligne++)
        for(int colonne=0; colonne<25; colonne++)
            _map_region[ligne][colonne]=0;
}
