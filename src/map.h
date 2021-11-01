#ifndef Map_H
#define Map_H

#include "matrix.h"
#include "point.h"
#include "listbuilding.h"
#include "todolist.h"
#include "pcolor.h"
#include <stdio.h>


#define ROW_MIN 10
#define COL_MIN 10
#define ROW_MAX 20
#define COL_MAX 30

// Koordinat Headquarter
// Ukuran Peta N+2xM+2 border *
// List Dinamis Building
// Warna Lokasi

typedef struct
{
   char contents[ROW_CAP][COL_CAP];
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Map;


/* *** Notasi Akses: Selektor Map *** */
#define ROWMap(PT) (PT).rowEff
#define COLMap(PT) (PT).colEff
#define ELMTMap(PT, i, j) (PT).contents[(i)][(j)]

/* ********** KONSTRUKTOR ********** */
void CreateMap(int N, int M, POINT HQ, ListBuilding LB, Map *PT);

void displayMap(Building NobitaLoc, Todolist l, Matrix M, Map *PT);

char getChar(int idx);


#endif


