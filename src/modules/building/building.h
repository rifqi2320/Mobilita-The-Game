#ifndef Building_H
#define Building_H

#include "../point/point.h"
#include <stdio.h>

typedef struct {
  POINT coordinate;
  char name;
} Building;

/* *** Notasi Akses: Selektor Building *** */
#define XCOORD(B) Absis((B).coordinate)
#define YCOORD(B) Ordinat((B).coordinate)
#define COORD(B) (B).coordinate
#define NAMEBUILDING(B) (B).name

void CreateBuilding(Building *B, int N, int M, char name);
/* I.S. B sembarang, N dan M bilangan positif */
/* F.S. B dengan posisi (N,M) dan nama name terbentuk*/

Building MARKBuilding();
/* Mengeluarkan building yang merupakan mark untuk list dan map */

boolean isMARKBuilding(Building B);
/* Mengeluarkan true jika B merupakan MARKBuilding */

boolean isEqualBuilding(Building B1, Building B2);
/* Mengeluarkan true jika posisi dan nama B1 sama persis dengan B2 */

#endif
