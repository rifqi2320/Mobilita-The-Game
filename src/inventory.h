#ifndef INVENTORY_H
#define INVENTORY_H

#include "gadget.h"

#define JUMLAHGADGET 5
#define IDX_UNDEF -1
#define VAL_UNDEF -999

typedef GADGET ElType;
typedef struct{
    ElType contents[JUMLAHGADGET];
} LIST_GADGET;

#define NAMAGADGET(G,i) (G).contents[(i)].nama
#define HARGAGADGET(G,i) (G).contents[(i)].harga
#define GADGET(G,i) (G).contents[(i)]

void MakeListGadget(LIST_GADGET *l);
int length(LIST_GADGET l);
boolean isIdxEff(LIST_GADGET l, int i);
boolean isFull(LIST_GADGET l);
void buyGadget(LIST_GADGET *l,LIST_GADGET buy,int i,int harga);
void useGadget(LIST_GADGET *l,int i);
void readList(LIST_GADGET *l);
void displayBuy(LIST_GADGET l);
void displayInventory(LIST_GADGET l);

#endif