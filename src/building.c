#include "point.h"
#include "point.c"
#include "building.h"
#include <stdio.h>

void CreateBuilding(Building *B, int N, int M, char name) {
  NAMEBUILDING(*B) = name;
  COORD(*B) = MakePOINT(M, N);
}

Building MARKBuilding() {
  Building tempb;
  CreateBuilding(&tempb, -1, -1, '0');
  return tempb;
}

boolean isMARKBuilding(Building B) {
  return (XCOORD(B) == -1 && YCOORD(B) == -1 && NAMEBUILDING(B) == '0');
}

boolean isEqualBuilding(Building B1, Building B2) {
  return (XCOORD(B1) == XCOORD(B2) && YCOORD(B1) == YCOORD(B2) &&
          NAMEBUILDING(B1) == NAMEBUILDING(B2));
}