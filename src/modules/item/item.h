#ifndef ITEM_H
#define ITEM_H

#include "../../utils/boolean.h"
#define TIME_UNDEF -1

typedef struct {
  char type;     /*Tipe item, N/H/P/V*/
  int value;     /*Value (harga) dari item*/
  int tArrival;  /*Waktu pesanan tiba*/
  int tPickup;   /*Waktu pesanan di angkut*/
  int tPerish;   /*Waktu pesanan perish dari waktu angkut*/
  char lPickup;  /*Lokasi pickup pesanan*/
  char lDropoff; /*Lokasi dropoff pesanan*/
} Item;

/*SELEKTOR*/
#define PICKUP(I) I.lPickup
#define DROPOFF(I) I.lDropoff
#define VALUE(I) I.value

/*KONSTRUKTOR*/
void CreateItem(Item *I, char type, int tArrival, int tPerish, char lPickup,
                char lDropoff);
/* I.S. Item sembarang dan input sesuai batasan */
/* F.S. Item terdefinisi sesuai dengan inputnya */
/*  -tPerish bernilai TIME_UNDEF jika type bukan 'P' */

/*PREDIKAT*/
boolean isItemArrived(Item I, int time);
/* Mengembalikan true jika waktu sekarang melebih waktu arrival */

boolean isItemExpired(Item I, int time);
/* Mengembalikan true jika waktu sekarang sudah melebihi waktu pickup+waktup
 * perish*/

boolean isItemPickedUp(Item I);
/* Mengembalikan true jika waktu pickup tidak TIME_UNDEF */

/*OPERASI*/
void pickupItem(Item *I, int time);
/* I.S. Item terdefinisi dan belum di pickup (tPickup == TIME_UNDEF)*/
/*   -lokasi mobita di lPickup */
/* F.S. Item di pickup dan tPickup == time */

void resetItem(Item *I);
/* I.S. Item terdefinisi dan telah di pickup (tPickup != Time UNDEF)*/
/* F.S. Waktu pickup di reset */

#endif