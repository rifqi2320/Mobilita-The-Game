#include "../src/list_linked.h"
#include "../src/item.h"
#include <stdio.h>

int main() {
  List l;
  Item I1, I2, I3, Temp;
  CreateList(&l);
  printf("Nilai kebenaran list kosong : %d\n", isListEmpty(l));
  char type, lPickup, lDropoff;
  int tArrival, tPerish;

  // Insert three item
  scanf(" %c %d %d %c %c", &type, &tArrival, &tPerish, &lPickup, &lDropoff);
  CreateItem(&I1, type, tArrival, tPerish, lPickup, lDropoff);
  
  scanf(" %c %d %d %c %c", &type, &tArrival, &tPerish, &lPickup, &lDropoff);
  CreateItem(&I2, type, tArrival, tPerish, lPickup, lDropoff);

  scanf(" %c %d %d %c %c", &type, &tArrival, &tPerish, &lPickup, &lDropoff);
  CreateItem(&I3, type, tArrival, tPerish, lPickup, lDropoff);
  
  insertPrio(&l, I1);
  insertLast(&l, I2);
  insertFirst(&l, I3);
  printf("Panjang list : %d\n", lengthList(l));
  printf("I1 indeks ke- %d\n", indexOf(l, I1));
  printf("I2 indeks ke- %d\n", indexOf(l, I2));
  printf("I3 indeks ke- %d\n", indexOf(l, I3));
  insertAt(&l, I2, 0);
  printf("I2 sekarang indeks ke- %d\n", indexOf(l, I2));
  printf("Panjang list setelah insert I2 di indeks ke 0 : %d\n", lengthList(l));
  
  deleteAt(&l, 0, &Temp);
  printf("Panjang list setelah delete elemen pertama: %d\n", lengthList(l));
  deleteFirst(&l, &Temp);
  printf("Panjang list setelah delete elemen pertama lagi: %d\n", lengthList(l));
  deleteLast(&l, &Temp);
  printf("Panjang list setelah delete elemen terakhir: %d\n", lengthList(l));
  printf("Nilai kebenaran list kosong : %d\n", isListEmpty(l));
  Temp = getElmt(l, 0);
  printf("Value : %d\n", VALUE(Temp));
  setElmt(&l ,0, I2);
  Temp = getElmt(l, 0);
  printf("Value setelah diubah : %d\n", VALUE(Temp));

  deleteLast(&l, &Temp);
  printf("Panjang list setelah delete elemen terakhir: %d\n", lengthList(l));
  return 0;
}