#include "Province.h"

void loadVenetie(int lgn, int col, int _map_region[25][25], int _map[25][25])
{

    int d_belluno, d_padova, d_rovigo, d_treviso, d_venezia, d_veronne, d_vicenza;
    for(int ligne=0; ligne<25;ligne++)
        for(int colonne=0; colonne<25; colonne++)
            _map[ligne][colonne]=0;

    ifstream donnee, f_belluno, f_padova, f_rovigo, f_treviso, f_venezia, f_veronne, f_vicenza;
    int compteur=0;
    donnee.open("venetie/venetie.txt");
    donnee >> d_belluno;
    donnee >> d_padova;
    donnee >> d_rovigo;
    donnee >> d_treviso;
    donnee >> d_venezia;
    donnee >> d_veronne;
    donnee >> d_vicenza;

    f_belluno.open("venetie/belluno.txt");
    f_belluno >> compteur;
    for(int i=0; i<compteur; i++)
    {
        f_belluno >> col;
        f_belluno >> lgn;
        _map_region[lgn][col]=d_belluno;
    }
    f_padova.open("venetie/padova.txt");
    f_padova >> compteur;
    for(int i=0; i<compteur; i++)
    {
        f_padova >> col;
        f_padova >> lgn;
        _map_region[lgn][col]=d_padova;
    }
    f_rovigo.open("venetie/rovigo.txt");
    f_rovigo >> compteur;
    for(int i=0; i<compteur; i++)
    {
        f_rovigo >> col;
        f_rovigo >> lgn;
        _map_region[lgn][col]=d_rovigo;
    }
    f_treviso.open("venetie/treviso.txt");
    f_treviso >> compteur;
    for(int i=0; i<compteur; i++)
    {
        f_treviso >> col;
        f_treviso>> lgn;
        _map_region[lgn][col]=d_treviso;
    }
    f_venezia.open("venetie/venezia.txt");
    f_venezia >> compteur;
    for(int i=0; i<compteur; i++)
    {
        f_venezia >> col;
        f_venezia >> lgn;
        _map_region[lgn][col]=d_venezia;
    }
    f_veronne.open("venetie/veronne.txt");
    f_veronne >> compteur;
    for(int i=0; i<compteur; i++)
    {
        f_veronne >> col;
        f_veronne >> lgn;
        _map_region[lgn][col]=d_veronne;
    }
    f_vicenza.open("venetie/vicenza.txt");
    f_vicenza >> compteur;
    for(int i=0; i<compteur; i++)
    {
        f_vicenza >> col;
        f_vicenza >> lgn;
        _map_region[lgn][col]=d_vicenza;
    }
}
