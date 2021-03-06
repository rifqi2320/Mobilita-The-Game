#ifndef Map_H
#define Map_H

#include "../listbuilding/listbuilding.h"
#include "../mapbuilding/mapbuilding.h"
#include "../pcolor/pcolor.h"
#include "../point/point.h"
#include "../todolist/todolist.h"
#include <stdio.h>

#define ROW_MIN 10
#define COL_MIN 10
#define ROW_MAX 20
#define COL_MAX 30

typedef struct {
  char contents[BUILDING_CAP][BUILDING_CAP];
  ListBuilding LB;
  MB MapB;
  int nBuilding; // jumlah
  int width;     // Lebar map
  int height;    // Panjang map
} Map;

/* *** Notasi Akses: Selektor Map *** */
#define WIDTHMap(PT) (PT).width
#define HEIGHTMap(PT) (PT).height
#define NBMap(PT) (PT).nBuilding
#define ELMTMap(PT, i, j) (PT).contents[(i)][(j)]
#define LBMap(PT) (PT).LB
#define MBMap(PT) (PT).MapB

/* ********** KONSTRUKTOR ********** */
void CreateMap(Map *PT, int N, int M, int L);

void displayMap(Map PT, Building NobitaLoc, Todolist l, InprogressList ip);

boolean isConnected(Map PT, Building B1, Building B2);

void addBuilding(Map *PT, Building B, int idx);

int displayIsReachable(Map PT, Building NobitaLoc);

Building getReachable(Map PT, Building NobitaLoc, int i);

#endif
