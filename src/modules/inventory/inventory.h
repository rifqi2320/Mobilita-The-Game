#ifndef INVENTORY_H
#define INVENTORY_H

#include "../../utils/boolean.h"
#include "../../utils/constant.h"
#include "../engine/engine.h"
#include "../gadget/gadget.h"
#include "../io/io.h"
#include "../listbuilding/listbuilding.h"
#include "../mobita/mobita.h"
#include "../tas/tas.h"
#include "../todolist/todolist.h"

#define JUMLAHGADGET 5

typedef GADGET ElType;
typedef struct {
  ElType contents[JUMLAHGADGET];
} LIST_GADGET;

#define NAMAGADGET(G, i) (G).contents[(i)].nama
#define HARGAGADGET(G, i) (G).contents[(i)].harga
#define GADGET(G, i) (G).contents[(i)]

void MakeListGadget(LIST_GADGET *l);   // Membuat List Gadget untuk Mobita
void MakeListGadgetHQ(LIST_GADGET *l); // Membuat List Gadget yang tersedia di
                                       // HQ
int lengthListGadget(LIST_GADGET l);
boolean isIdxEff(LIST_GADGET l, int i);
boolean isLGFull(LIST_GADGET l);
void buyGadget(LIST_GADGET *l, LIST_GADGET buy,
               MOBITA *MOB); // Procedure membeli Gadget
void useGadget(LIST_GADGET *l, Tas *t, MOBITA *MOB, InprogressList *ip,
               ListBuilding h); // Procedure Menggunakan Gadget
void displayBuy(LIST_GADGET l); // Display List gadget yang bisa di beli di HQ
void displayInventory(LIST_GADGET l); // Display List Gadget yang dimiliki
                                      // Mobita
void process(GADGET gad, Tas *t, MOBITA *MOB, InprogressList *ip,
             ListBuilding h); // Melakukan proses pemakaian Gadget
void KainWaktu(
    Tas *t,
    InprogressList *ip); // Memproses penggunaan gadget Kain Pembungkus waktu
void SenterPembesar(Tas *t); // Memproses penggunaan gadget Senter Pembesar
void PintuKemanaSaja(
    MOBITA *MOB,
    ListBuilding h); // Memproses penggunaan gadget Pintu Kemana Saja
void MesinWaktu(Tas *t,
                InprogressList *ip); // Memproses penggunaan gadget Mesin Waktu
void SenterPengecil(Tas *t,
                    MOBITA *mob); // Memproses penggunaan gadget Senter Pengecil
void checkEffectSenter(Tas *t,
                       MOBITA *mob); // Melakukan pengecekan dan pengubahan tipe
                                     // item jika efek senter pengecil ada

#endif