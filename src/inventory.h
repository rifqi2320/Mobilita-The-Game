#ifndef INVENTORY_H
#define INVENTORY_H

#include "boolean.h"
#include "gadget.h"
#include "mobita.h"
#include "tas.h"
#include "listbuilding.h"
#include "todolist.h"
#include "constant.h"

#define JUMLAHGADGET 5

typedef GADGET ElType;
typedef struct{
    ElType contents[JUMLAHGADGET];
} LIST_GADGET;

#define NAMAGADGET(G,i) (G).contents[(i)].nama
#define HARGAGADGET(G,i) (G).contents[(i)].harga
#define GADGET(G,i) (G).contents[(i)]

void MakeListGadget(LIST_GADGET *l);
int lengthListGadget(LIST_GADGET l);
boolean isIdxEff(LIST_GADGET l, int i);
boolean isLGFull(LIST_GADGET l);
void buyGadget(LIST_GADGET *l,LIST_GADGET buy,int i,int harga);
void useGadget(LIST_GADGET *l,int i,Tas *t, MOBITA *MOB,InprogressList *ip, ListBuilding h);
void displayBuy(LIST_GADGET l);
void displayInventory(LIST_GADGET l);
void process(GADGET gad,Tas *t, MOBITA *MOB,InprogressList *ip, ListBuilding h);
void KainWaktu(Tas *t, InprogressList *ip);
void SenterPembesar(Tas *t);
void PintuKemanaSaja(MOBITA *MOB,ListBuilding h);
void MesinWaktu();
void SenterPengecil(Tas *t);

#endif