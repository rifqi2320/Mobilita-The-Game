#include "building.h"
#include "point.h"
#include <stdio.h>

void CreateBuilding(Building *B, int N, int M, char name) {
  NAMEBUILDING(*B) = name;
  COORD(*B) = MakePOINT(N, M);
}

Building MARKBuilding() {
  Building tempb;
  CreateBuilding(&tempb, -1, -1, '0');
  return tempb;
}

boolean isMARKBuilding(Building B) {
  return (XCOORD(B) == -1 && YCOORD(B) == -1 && NAMEBUILDING(B) == '0');
}