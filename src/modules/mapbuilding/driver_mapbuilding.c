#include "mapbuilding.h"
#include <stdio.h>

int main() {
  MB mb;
  CreateMB(&mb);
  char building = 'C';
  setVal(&mb, building, 1);
  int val = getVal(mb, building);
  printf("val building %c adalah %d\n", building, val);

  building = 'B';
  setVal(&mb, building, 0);
  val = getVal(mb, building);
  printf("val building %c adalah %d\n", building, val);
  return 0;
}