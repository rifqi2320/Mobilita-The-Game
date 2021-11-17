#include "queuetodo.h"
#include <stdio.h>

int main() {
  Queue q;
  CreateQueue(&q);

  // N 2 5 P D
  Item I;
  char type, lPickup, lDropoff;
  int tArrival, tPerish;
  scanf("%c %d %d %c %c", &type, &tArrival, &tPerish, &lPickup, &lDropoff);
  CreateItem(&I, type, tArrival, tPerish, lPickup, lDropoff);
  enqueue(&q, I);
  printf("Nilai kebenaran queue kosong : %d\n", isQueueEmpty(q));
  printf("Nilai kebenaran queue penuh : %d\n", isQueueFull(q));
  int len = lengthQueue(q);
  printf("Panjang queue = %d\n", len);

  Item val;
  dequeue(&q, &val);
  len = lengthQueue(q);
  printf("Panjang queue setelah dihapus = %d\n", len);
  printf("Nilai value item yang dihapus = %d\n", VALUE(I));
  printf("PICKUP item yang dihapus = %c\n", PICKUP(I));
  printf("NDROPOFFilai value item yang dihapus = %c\n", DROPOFF(I));
  return 0;
}