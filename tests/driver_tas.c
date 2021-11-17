#include "../src/tas.h"
#include <stdio.h>

int main() {
  Tas t;
  Item N, V, H;
  CreateTas(&t);
  CreateItem(&N, 'N', 2, 2, 'A', 'B');
  CreateItem(&V, 'V', 2, 2, 'A', 'B');
  CreateItem(&H, 'H', 2, 2, 'A', 'B');
  printf(isTasEmpty(t) ? "Tas kosong\n" : "Tas tidak kosong\n");
  push(&t, N);
  printf(isTasEmpty(t) ? "Tas kosong\n" : "Tas tidak kosong\n");
  push(&t, N);
  push(&t, N);
  printf(isTasFull(t) ? "Tas penuh\n" : "Tas tidak penuh\n");
  int i;
  for (i = 0; i < 10; i++) {
    increaseCapacity(&t);
  }
  printf(isTasFull(t) ? "Tas penuh\n" : "Tas tidak penuh\n");
  push(&t, N);
  printf(isTasFull(t) ? "Tas penuh\n" : "Tas tidak penuh\n");
  push(&t, H);
  push(&t, H);
  printf("There are %d Heavy items in the bag\n", numOfHeavy(t));
  push(&t, V);
  printf(isVIPinTop(t) ? "VIP in TOP\n" : "VIP not in top\n");
  push(&t, N);
  printf(isVIPinTop(t) ? "VIP in TOP\n" : "VIP not in top\n");
  return 0;
}