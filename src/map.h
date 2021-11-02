#ifndef Map_H
#define Map_H

#include "matrix.h"
#include "point.h"
#include "graph.h"
#include "listbuilding.h"
#include "todolist.h"
#include "pcolor.h"
#include <stdio.h>


#define ROW_MIN 10
#define COL_MIN 10
#define ROW_MAX 20
#define COL_MAX 30

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
void CreateMap(Map *PT, int N, int M, POINT HQ, ListBuilding LB);

void displayMap(Map *PT, Building NobitaLoc, Todolist l, Matrix M);

char getChar(int idx);


#endif


