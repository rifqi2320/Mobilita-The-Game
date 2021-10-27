#include "../src/item.c"
#include <stdio.h>

void main() {
  Item I;
  CreateItem(&I, 'N', 2, 2, 'A', 'B');
  printf(isItemArrived(I, 3) ? "I has arrived " : "I hasn't arrived ");
  printf("when time = 3\n");
  pickupItem(&I, 3);
  printf("I is picked up at time = 3\n");
  printf(isItemExpired(I, 4) ? "I has expired\n" : "I hasn't expired\n");
  printf("when time = 4\n");
  resetItem(&I);
  printf("Item I has been returned\n");
  printf(isItemPickedUp(I) ? "Item I is picked up\n"
                           : "Item I hasn't been picked up\n");
}