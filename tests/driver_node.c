#include "../src/node.h"
#include <stdio.h>


int main() {
  Item I;
  char type, lPickup, lDropoff;
  int tArrival, tPerish;
  scanf("%c %d %d %c %c", &type, &tArrival, &tPerish, &lPickup, &lDropoff);
  CreateItem(&I, type, tArrival, tPerish, lPickup, lDropoff);
  Address p = newNode(I);

  if (p != NULL) {
    printf("Value item = %d \n", VALUE(INFO(p)));
    printf("Lokasi pickup item = %c \n", PICKUP(INFO(p)));
    printf("Lokasi dropoff item = %c \n", DROPOFF(INFO(p)));
  } else {
    printf("Alokasi gagal\n");
  }
  return 0;
}