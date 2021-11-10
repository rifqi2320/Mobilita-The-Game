#include "building.h"
#include "point.h"
#include <stdio.h>

void CreateBuilding(Building *B, int N, int M, char name) {
  NAMEBUILDING(*B) = name;
  COORD(*B) = MakePOINT(N, M);
}