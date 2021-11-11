#include "inventory.h"
#include "engine.h"
#include <stdio.h>

int waktu;

void MakeListGadget(LIST_GADGET *l) {
  for (int i = 0; i < JUMLAHGADGET; i++) {
    NAMAGADGET(*l, i) = "-";
    HARGAGADGET(*l, i) = VAL_UNDEF;
  }
}

void MakeListGadgetHQ(LIST_GADGET *l) {
  for (int i = 0; i < JUMLAHGADGET; i++) {
    if(i==0){
      NAMAGADGET(*l, i) = "Kain Pembungkus Waktu";
      HARGAGADGET(*l, i) = 800;
    }
    else if(i==1){
      NAMAGADGET(*l, i) = "Senter Pembesar";
      HARGAGADGET(*l, i) = 1200;
    }
    else if(i==2){
      NAMAGADGET(*l, i) = "Pintu Kemana Saja";
      HARGAGADGET(*l, i) = 1500;
    }
    else if(i==3){
      NAMAGADGET(*l, i) = "Mesin Waktu";
      HARGAGADGET(*l, i) = 3000;
    }
    else{
      NAMAGADGET(*l, i) = "Senter Pengecil";
      HARGAGADGET(*l, i) = 800;
    }
  }
}

int lengthListGadget(LIST_GADGET l) {
  int ctr = 0;
  for (int i = 0; i < JUMLAHGADGET; i++) {
    if (NAMAGADGET(l, i) != "-") {
      ctr++;
    }
  }
  return ctr;
}

boolean isIdxEff(LIST_GADGET l, int i) {
  if (NAMAGADGET(l, i) != "-") {
    return true;
  }
  return false;
}
boolean isLGFull(LIST_GADGET l) {
  if (lengthListGadget(l) == JUMLAHGADGET) {
    return true;
  }
  return false;
}
void buyGadget(LIST_GADGET *l, LIST_GADGET buy, int i, MOBITA *MOB) {
  if (isLGFull(*l)) {
    printf("Inventory sudah penuh!\n");
  } else if (isIdxEff(buy, i)) {
    if (HARGAGADGET(buy, i) > Uang(*MOB)) {
      printf("Uang tidak cukup untuk membeli Gadget!\n");
    } else {
      Uang(*MOB) -= HARGAGADGET(buy, i);
      for (int j = 0; j < JUMLAHGADGET; j++) {
        if (NAMAGADGET(*l, j) == "-") {
          NAMAGADGET(*l, j) = getName(GADGET(buy, i));
          HARGAGADGET(*l, j) = getPrice(GADGET(buy, i));
        }
      }
    }
  } else {
    printf("Gadget tidak ditemukan.\n");
  }
}

void useGadget(LIST_GADGET *l, int i, Tas *t, MOBITA *MOB, InprogressList *ip,
               ListBuilding h) {
  GADGET gad;
  if (isIdxEff(*l, i)) {
    NAMA(gad) = NAMAGADGET(*l, i);
    HARGA(gad) = HARGAGADGET(*l, i);
    NAMAGADGET(*l, i) = "-";
    HARGAGADGET(*l, i) = VAL_UNDEF;
    process(gad, t, MOB, ip, h);
  } else {
    printf("Tidak ada gadget yang dapat digunakan");
  }
}

void displayBuy(LIST_GADGET l) {
  printf("Gadget yang tersedia:\n");
  for (int i = 0; i < JUMLAHGADGET; i++) {
    printf("%d. %s (%d Yen)\n", i + 1, NAMAGADGET(l, i), HARGAGADGET(l, i));
  }
}

void process(GADGET gad, Tas *t, MOBITA *MOB, InprogressList *ip,
             ListBuilding h) {
  if (NAMA(gad) == "Kain Pembungkus Waktu") {
    KainWaktu(t, ip);
  } else if (NAMA(gad) == "Senter Pembesar") {
    SenterPembesar(t);
  } else if (NAMA(gad) == "Pintu Kemana Saja") {
    PintuKemanaSaja(MOB, h);
  } else if (NAMA(gad) == "Mesin Waktu") {
    MesinWaktu();
  } else if (NAMA(gad) == "Senter Pengecil") {
    SenterPengecil(t);
  }
}

void KainWaktu(Tas *t, InprogressList *ip) {
  if (TOP(*t).type == 'P') {
    TOP(*t).tPerish += waktu - TOP(*t).tPickup;
    Address now = FIRST(*ip);
    while (NEXT(now) != NULL) {
      now = NEXT(now);
    }
    INFO(now).tPerish += waktu - TOP(*t).tPickup;
    printf("Senter Pengecil berhasil digunakan!");
  } else {
    printf("Kain Pembungkus Waktu gagal digunakan!Kain terbuang.");
  }
}

void SenterPembesar(Tas *t) {
  t->capacity *= 2;
  if (t->capacity > 100) {
    t->capacity = 100;
  }
  printf("Senter Pembesar berhasil digunakan!");
}

void PintuKemanaSaja(MOBITA *MOB, ListBuilding h) {
  boolean pindah = false;
  while (!pindah) {
    displayListBuilding(h);
    int x;
    scanf("%d", &x);
    if (x > 0 && x <= lengthListBuilding(h)) {
      pindah = true;
      printf("Mobita berhasil pindah ke (%d %d).\n",
             XCOORD(ELMTListB(h, x - 1)), YCOORD(ELMTListB(h, x - 1)));
      Posisi(*MOB) = ELMTListB(h, x - 1);
    } else {
      printf("Lokasi tidak ditemukan, silahkan ulangi.\n");
    }
  }
}

void MesinWaktu() {
  waktu -= 50;
  if (waktu < 0) {
    waktu = 0;
  }
  printf("Mesin Waktu berhasil digunakan!");
}

void SenterPengecil(Tas *t) {
  if (TOP(*t).type == 'H') {
    TOP(*t).type = 'S';
    printf("Senter Pengecil berhasil digunakan!");
  } else {
    printf("Senter Pengecil gagal digunakan!Senter terbuang.");
  }
}

void displayInventory(LIST_GADGET l) {
  for (int i = 0; i < JUMLAHGADGET; i++) {
    printf("%d. %s\n", i + 1, NAMAGADGET(l, i));
  }
}