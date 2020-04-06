#ifndef NOM_H_INCLUDED
#define NOM_H_INCLUDED

#include <string>
#include <iostream>

#define VAL_D_AOSTE 1
#define DIEMONT 2
#define LIGURIA 3
using namespace std;


int val_d_Aoste[2][2] = {{3, 0}, {3, 1}};
int diemont[17][2] = {
{2, 3},
{3,2}, {3,3},
{4,1}, {4,2}, {4,3},
{5,0}, {5,1}, {5,0}, {5,1}, {5,2}, {5,3}, {5,4},
{6,0}, {6,1}, {6,2}, {7,1}
};

int liguria[5][2] = {
{6,3}, {6,4},
{7,2}, {7,5}, {7,6}
};

int lombarie[12][2] = {
{1,7},
{2,5}, {2,6}, {2,7},
{3,4}, {3,5}, {3,6}, {3,7},
{4,4}, {4,5}, {4,6}, {4,7},
};

int trentin[6][2] = {
{0,9}, {0,10},
{1,8}, {1,9},
{2,8}, {2,9}
};

int venetie[9][2] = {
{1,10},
{2,10}, {3,8}, {3,9}, {3,10}, {3,11},
{4,8}, {4,9}, {4,10}
};

int v_julienne[7][2] = {
{1,11}, {1,12},
{2,11}, {2,12}, {1,12},
{3,12}, {3,13},
};

int romagne[15][2] = {
{5,5}, {5,6}, {5,7}, {5,8}, {5,9}, {5,10},
{6,5}, {6,6}, {6,7}, {6,8}, {6,9}, {6,10},
{7,8}, {7,10}, {7,11}
};

int toscane[14][2] = {
{7,6}, {7,7}, {7,9},
{8,7}, {8,8}, {8,9}, {8,10},
{9,7}, {9,8}, {9,9}, {9,10},
{10,8}, {10,9}, {11,9},
};

int ombrie[5][2] = {
{9,11}, {9,12},
{10,10}, {10,11}, {10,12},
};
int marches[5][2] = {
{8,11}, {8,12}, {8,13},
{9,13}, {9,14}
};
int abruzzes[7][2] = {
{10,13}, {10,14},
{11,13}, {11,14}, {11,15},
{12,13}, {12,14}
};

int latium[8][2] = {
{11,10}, {11,11}, {11,12},
{12,11}, {12,12},
{13,12}, {13,13}, {13,14}
};
int molise[4][2] = {
{12,15}, {12,16},
{13,15}, {13,16}
};
int campania[9][2] = {
{13,17},
{14,15}, {14,16}, {14,17},
{15,16}, {15,17}, {15,18},
{16,17}, {16,18}
};
int pouilles[14][2] = {
{12,17}, {12,18}, {12,19},
{13,18}, {13,19}, {13,20},
{14,20}, {14,21}, {14,22}, {14,23},
{15,22}, {15,23}, {15,24}, {16,24}
};

int brasilicate[10][2] = {
{14,18}, {14,19}, {15,19}, {15,20}, {15,21},
{16,19}, {15,20}, {15,21},
{16,19}, {16, 20}
};

int calibre[12][2] = {
{17,19}, {17,20}, {17,21},
{18,20}, {18,21}, {18,22},
{19,20}, {19,21},
{20,20}, {20,21},
{21,19}, {21,20}
};
int sicile[19][2] = {
{21,14}, {21,18}, {21,19},
{22,12}, {22,13}, {22,14}, {22,15}, {22,16}, {22,17}, {22,18}, {22,19},
{23,14}, {23,15}, {23,16}, {23,17}, {23,18}, {23,19},
{24,18}, {24,19}
};

int sardaigne[13][2] = {
{14,5},
{15,3}, {15,4}, {15,5},
{16,3}, {16,4}, {16,5},
{17,4}, {17,5},
{18,4}, {18,5},
{19,4}, {19,5}
};



int region[25][25][1];





#endif
