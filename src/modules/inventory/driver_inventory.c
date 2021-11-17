#include "inventory.h"
#include <stdio.h>

int main() {
  LIST_GADGET l1, l2;
  Tas t;
  MOBITA M;
  ListBuilding LB;
  InprogressList ip;
  Building a;
  XCOORD(a) = 3;
  YCOORD(a) = 3;
  NAMEBUILDING(a) = '8';

  MakeListGadget(&l2);
  CreateTas(&t);
  MakeListGadgetHQ(&l1);
  CreateInProgress(&ip);
  CreateMobita(&M, a);
  CreateListBuilding(&LB, 1);
  ELMTListB(LB, 0) = a;

  Uang(M) = 70000;

  if (isLGFull(l1)) {
    printf("List L1 penuh.\n");
    printf("%d %d\n", lengthListGadget(l1), lengthListGadget(l2));
  }

  int i;
  for (i = 0; i < 6; i++) {
    buyGadget(&l2, l1, &M);
  }

  int j;
  for (j = 0; j < JUMLAHGADGET; j++) {
    useGadget(&l2, &t, &M, &ip, LB);
  }
  return 0;
}