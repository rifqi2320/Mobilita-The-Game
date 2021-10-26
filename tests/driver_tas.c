#include "../src/item.c"
#include "../src/tas.c"
#include <stdio.h>

void main() {
  Tas t;
  Item I;
  CreateTas(&t);
  CreateItem(&I, 'N', 2, 2, 'A', 'B');
  printf(isTasEmpty(t) ? "Tas kosong\n" : "Tas tidak kosong\n");
  push(&t, I);
  printf(isTasEmpty(t) ? "Tas kosong\n" : "Tas tidak kosong\n");
  push(&t, I);
  push(&t, I);
  printf(isTasFull(t) ? "Tas penuh\n" : "Tas tidak penuh\n");
  increaseCapacity(&t);
  printf(isTasFull(t) ? "Tas penuh\n" : "Tas tidak penuh\n");
  push(&t, I);
  printf(isTasFull(t) ? "Tas penuh\n" : "Tas tidak penuh\n");
}