#ifndef Building_H
#define Building_H

#include "point.h"
#include <stdio.h>

#define BUILDING_CAP  26

typedef struct
{
   POINT coordinate;
   char name;
} Building;

/* *** Notasi Akses: Selektor Building *** */
#define XCOORD(B) Absis((B).coordinate)
#define YCOORD(B) Ordinat((B).coordinate)
#define NAME(B) (B).name

void CreateBuilding(int N, int M, char name);

#endif
