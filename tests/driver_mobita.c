#include "../src/mobita.h"
#include <stdio.h>

int main() {
  MOBITA MOB;
  Building hq;
  XCOORD(hq) = 2;
  YCOORD(hq) = 2;
  CreateMobita(&MOB, hq);
  addAbility(&MOB, 's');
  addAbility(&MOB, 'r');

  Building a;
  XCOORD(a) = 3;
  YCOORD(a) = 3;

  move(&MOB, a);
  removeAbility(&MOB, 's');
  XCOORD(a) = 3;
  YCOORD(a) = 2;
  move(&MOB, a);

  return 0;
}